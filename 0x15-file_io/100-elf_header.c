#include "main.h"

/**
 * main - Entry point. Displays information contained in an ELF header.
 *
 * @argc: Number of arguments passed to the program.
 * @argv: Array of strings containing the arguments passed to the program.
 *
 * Return: On success, returns EXIT_SUCCESS. On failure, returns EXIT_FAILURE.
 */
int main(int argc, char **argv)
{
	int fd, res;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		return (EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Cannot read file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	res = read(fd, &header, sizeof(header));
	if (res != sizeof(header))
	{
		dprintf(STDERR_FILENO, "Error: Cannot read ELF header of file %s\n", argv[1]);
		close(fd);
		return (EXIT_FAILURE);
	}

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
	    header.e_ident[EI_MAG1] != ELFMAG1 ||
	    header.e_ident[EI_MAG2] != ELFMAG2 ||
	    header.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: %s is not an ELF file\n", argv[1]);
		close(fd);
		return (EXIT_FAILURE);
	}

	printf("Magic:   %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
		   header.e_ident[EI_MAG0], header.e_ident[EI_MAG1], header.e_ident[EI_MAG2],
		   header.e_ident[EI_MAG3], header.e_ident[EI_CLASS], header.e_ident[EI_DATA],
		   header.e_ident[EI_VERSION], header.e_ident[EI_OSABI], header.e_ident[EI_ABIVERSION],
		   header.e_type, header.e_machine, header.e_version);

	printf("Class:                             %s\n", header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("Data:                              %s\n", header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
	printf("Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
	printf("OS/ABI:                            %s\n", get_osabi_name(header.e_ident[EI_OSABI]));
	printf("ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
	printf("Type:                              %s\n", get_type_name(header.e_type));
	printf("Entry point address:               0x%lx\n", header.e_entry);

	close(fd);
	return (EXIT_SUCCESS);
}
