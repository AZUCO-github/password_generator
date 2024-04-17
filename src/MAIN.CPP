///////////////////////////////////////////////////////////////////////////////
//	Password Generator
///////////////////////////////////////////////////////////////////////////////

#include	<windows.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>

#define		DEFAULT_PASSWORD_LENGTH	32
#define		DEFAULT_GENERATE_TIMES	10
#define		DISABLE_UPPER			1<<0
#define		DISABLE_LOWER			1<<1
#define		DISABLE_NUMERIC			1<<2
#define		DISABLE_SYMBOL			1<<3
#define		DISABLE_SPACE			1<<4
#define		DISABLE_DOUBLE_QUOTE	1<<5
#define		DISABLE_COMMA			1<<6
#define		DISABLE_CONTROL			1<<7


int	main(int argc, char* argv[])
{
	unsigned long	option_mode =
		DISABLE_SPACE |
		DISABLE_DOUBLE_QUOTE |
		DISABLE_COMMA |
		DISABLE_CONTROL;
	unsigned long	password_length = DEFAULT_PASSWORD_LENGTH;
	unsigned long	generate_times = DEFAULT_GENERATE_TIMES;
	unsigned long	fnargc = 0;
	unsigned long	tul;

	///////	option	///////////////////////////////////////////////////////////////
	for (tul = 1; tul < argc; tul++) {
		if (argv[tul][0] == '/') {
			if (argv[tul][1] == 'u')	option_mode |= DISABLE_UPPER;
			if (argv[tul][1] == 'l')	option_mode |= DISABLE_LOWER;
			if (argv[tul][1] == 'n')	option_mode |= DISABLE_NUMERIC;
			if (argv[tul][1] == 's')	option_mode |= DISABLE_SYMBOL;
			if (argv[tul][1] == 'd') {
				sscanf(&argv[tul][2], "%d", &password_length);
				printf("<debug>	password_length = %d\n", password_length);
				if (password_length == 0)	password_length = DEFAULT_PASSWORD_LENGTH;
			}
			if (argv[tul][1] == 't') {
				sscanf(&argv[tul][2], "%d", &generate_times);
				printf("<debug>	generate_times = %d\n", generate_times);
				if (generate_times == 0)	generate_times = DEFAULT_GENERATE_TIMES;
			}
			if (argv[tul][1] == '?') {
				printf("password_generator <option>\n");
				printf("\t/u\tdisable alphabet upper\n");
				printf("\t/l\tdisable alphabet lower\n");
				printf("\t/n\tdisable numeric\n");
				printf("\t/s\tdisable symbol\n");
				printf("\t/d<d>\tpassword length\n");
				printf("\t/t<d>\tgenerat times\n");
				exit(-1);
			}
		}
		else {
			if (fnargc == 0)	fnargc = tul;
		}
	}



	///////	password generate ///////////////////////////////////////////////////////////////
	srand((unsigned int)time(NULL));

	for (unsigned long generate_times_count = 0; generate_times_count < generate_times; generate_times_count++) {
		for (unsigned long password_length_count = 0; password_length_count < password_length; password_length_count++) {
		password_charactor_generate:
			unsigned char	password_charactor = (unsigned char)rand();

			if (option_mode & DISABLE_CONTROL) {
				if ((password_charactor >= 0x00) && (password_charactor <= 0x1f))
					goto	password_charactor_generate;
				if ((password_charactor >= 0x7f) && (password_charactor <= 0xff))
					goto	password_charactor_generate;
			}

			if (option_mode & DISABLE_SYMBOL) {
				if ((password_charactor >= 0x21) && (password_charactor <= 0x2f))
					goto	password_charactor_generate;
				if ((password_charactor >= 0x3a) && (password_charactor <= 0x40))
					goto	password_charactor_generate;
				if ((password_charactor >= 0x5b) && (password_charactor <= 0x60))
					goto	password_charactor_generate;
				if ((password_charactor >= 0x7b) && (password_charactor <= 0x7e))
					goto	password_charactor_generate;
			}

			if (option_mode & DISABLE_NUMERIC) {
				if ((password_charactor >= 0x30) && (password_charactor <= 0x39))
					goto	password_charactor_generate;
			}

			if (option_mode & DISABLE_UPPER) {
				if ((password_charactor >= 0x41) && (password_charactor <= 0x5a))
					goto	password_charactor_generate;
			}

			if (option_mode & DISABLE_LOWER) {
				if ((password_charactor >= 0x61) && (password_charactor <= 0x7a))
					goto	password_charactor_generate;
			}

			if (option_mode & DISABLE_SPACE) {
				if (password_charactor < 0x20)	goto	password_charactor_generate;
			}

			if (option_mode & DISABLE_DOUBLE_QUOTE) {
				if (password_charactor < '"')	goto	password_charactor_generate;
			}

			if (option_mode & DISABLE_COMMA) {
				if (password_charactor < ',')	goto	password_charactor_generate;
			}



			printf("%c", password_charactor);
		}
		printf("\n");
	}
}



