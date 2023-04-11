#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void check_elf(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void close_elf(int fd);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
/**
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF.
 *
 * Description: If ELF file - exit code 98.
 */
void check_elf(unsigned char *magic_numbers)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (magic_numbers[i] != 127 &&
		    magic_numbers[i] != 'E' &&
		    magic_numbers[i] != 'L' &&
		    magic_numbers[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - Prints the magic numbers of an ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *magic_numbers)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", magic_numbers[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - Prints the class ELF header.
 * @e_ident: A pointer to an ELF class.
 */
void print_class(unsigned char *class_ident)
{
	printf("  Class:                             ");

	switch (class_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", class_ident[EI_CLASS]);
	}
}

/**
 * print_data - Prints the data of an ELF header.
 * @e_ident: A pointer to an ELF class.
 */
void print_data(unsigned char *data_ident)
{
	printf("  Data:                              ");

	switch (data_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", data_ident[EI_CLASS]);
	}
}

/**
 * print_version - Prints the version of an ELF header.
 * @e_ident: A pointer to an ELF version.
 */
void print_version(unsigned char *version_ident)
{
	printf("  Version:                           %d",
	       version_ident[EI_VERSION]);

	switch (version_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}
/**
 * print_osabi - Prints the OS/ABI of an ELF header.
 * @e_ident: A pointer to an ELF version.
 */
void print_osabi(unsigned char *my_e_ident)
{
	printf("  OS/ABI:                            ");

	switch (my_e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", my_e_ident[EI_OSABI]);
	}
}
/**
 * print_abi - Prints the ABI version of an ELF header.
 * @my_e_ident: A pointer to an ELF ABI version.
 */
void print_abi(unsigned char *my_e_ident)
{
	printf("  ABI Version:                       %d\n",
	       my_e_ident[EI_ABIVERSION]);
}
/**
 * print_type - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an ELF class.
 */
void print_type(unsigned int type, unsigned char *ident)
{
	if (ident[EI_DATA] == ELFDATA2MSB)
		type >>= 8;

	printf("  Type:                              ");

	switch (type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", type);
	}
}

/**
 * print_entry - Prints the ELF header.
 * @entry: The address of the ELF entry point.
 * @ident: A pointer to an ELF class.
 */
void print_entry(unsigned long int entry, unsigned char *ident)
{
	printf("  Entry point address:               ");

	if (ident[EI_DATA] == ELFDATA2MSB)
	{
		entry = ((entry << 8) & 0xFF00FF00) |
			  ((entry >> 8) & 0xFF00FF);
		entry = (entry << 16) | (entry >> 16);
	}

	if (ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)entry);

	else
		printf("%#lx\n", entry);
}

/**
 * close_elf - Closes an ELF file.
 * @fd: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", fd);
		exit(98);
	}
}
/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *my_header;
	int my_o, my_r;

	my_o = open(argv[1], O_RDONLY);
	if (my_o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	my_header = malloc(sizeof(Elf64_Ehdr));
	if (my_header == NULL)
	{
		close_elf(my_o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	my_r = read(my_o, my_header, sizeof(Elf64_Ehdr));
	if (my_r == -1)
	{
		free(my_header);
		close_elf(my_o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(my_header->e_ident);
	printf("ELF Header:\n");
	print_magic(my_header->e_ident);
	print_class(my_header->e_ident);
	print_data(my_header->e_ident);
	print_version(my_header->e_ident);
	print_osabi(my_header->e_ident);
	print_abi(my_header->e_ident);
	print_type(my_header->e_type, my_header->e_ident);
	print_entry(my_header->e_entry, my_header->e_ident);

	free(my_header);
	close_elf(my_o);
	return (0);
}

