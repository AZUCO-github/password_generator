#ifndef		_AZU_LE_
#define		_AZU_LE_

#define	LESL(c1,c2)((unsigned long)((c1<<16)|c2))
#define	LECL(c1,c2,c3,c4)((unsigned long)((c1<<24)|(c2<<16)|(c3<<8)|c4))
#define	LECS(c1,c2)((unsigned long)((c1<<8)|c2))
#define	LEL1(l1)((unsigned char)(l1>>24))
#define	LEL2(l1)((unsigned char)(l1>>16))
#define	LEL3(l1)((unsigned char)(l1>>8))
#define	LEL4(l1)((unsigned char) l1)

extern	unsigned short	ler2(unsigned char *);
extern	unsigned long	ler4(unsigned char *);
extern	void			lew2(unsigned char *,unsigned short);
extern	void			lew4(unsigned char *,unsigned long);

#endif		_AZU_LE_
