/*  GIMP header image file format (RGB): /home/cypher-nex/42cursus/so_long/textures/includes.h  */

static unsigned int width = 16;
static unsigned int height = 16;

/*  Call this macro repeatedly.  After each use, the pixel data can be extracted  */

#define HEADER_PIXEL(data,pixel) {\
pixel[0] = (((data[0] - 33) << 2) | ((data[1] - 33) >> 4)); \
pixel[1] = ((((data[1] - 33) & 0xF) << 4) | ((data[2] - 33) >> 2)); \
pixel[2] = ((((data[2] - 33) & 0x3) << 6) | ((data[3] - 33))); \
data += 4; \
}
static char *header_data =
	"IJ79C8B]C8B]C8B]C8B]C8B]C8B]C8B]C8B]C8B]C8B]C8B]C8B]C8B]C8B]IJ79"
	"C8B];EB2=5V7<5R5<5R5<5R5=EZ8<UR6<5R5<5R5<5R5<ER6=%R6<UV6:E>1C8B]"
	"C8B]:U>1=U^9=%V7?6*<=U^9>&\"9=5Z7<ER6?6*<>F&:=U^9=EZ7<5R5;UJ3C8B]"
	"C8B];5F3@62>>5^9>&\":?V2>>6&:?&*<?&&;=V\"9?V2>>V*;>F&:>V\":<UR6C8B]"
	"C8B]=%V7?6*<?V2>>6*;?&.<?F2>>F&:A&>A>6*;?&.<?&.=?V2>@&2><%N4C8B]"
	"C8B];5F3=UZ8=EZ8=%Z7=5Z8=5Z8>6\":=%V6=%Z7=5Z8=5Z7=U^9=UZ8;%B2C8B]"
	"C8B];EF3>%^9>F\":>6&:?6*<=U^9>%^9>%^9=U^9?6*<=U^9>%^9>%^9;UF3C8B]"
	"C8B];5B2>6\":=%Z7?6.=>&\"9>F&;=UZ8=%Z7>V*;>F&;>&\":>%^9=%Z7;5F2C8B]"
	"C8B]<%N4A&>A?6*<?62=@V:@?62=@&6??V.=?62=@F:@?V6>?62=?6*<>%^9C8B]"
	"C8B];EF3>%^9>F&:=5Z8=5^8=E^8=%V7?F.==%Z7=5^8=5^8=U^9>V&;;5F2C8B]"
	"C8B]<5N5=EZ8=%Z7=%Z7=E^8>6\":>%^9=%V7=%Z7=E^8=U^9>6\":=EV7;%B2C8B]"
	"C8B];5B2=U^8?&&;>F&:?F.<=5Z8>6\":>5^9>&\"9?F.==U^9>&\"9>5^9;UJ3C8B]"
	"C8B]<5J4@&2>>6*;@F:@?6.=@66??&*<>6*;@&6>?V2>?62=?F*=>V*<;UN4C8B]"
	"C8B];5F3>V*;>%^9=V\"9>6&:=V\"9>&\":>5^9>6&:>6&:>&\"9=V\"9=UZ8=%V7C8B]"
	"CHB]:5:/<EN5;5B2;5F2<UN5;EF3<%J4;EF3;%B1<UN5<%J4;EF3;UF3:E>0CHB]"
	"L*G=GI#&GI#&GI#&GI#&GI#&GI#&GI#&GI#&GI#&GI#&GI#&GI#&GI#&GI#&L*G="
	"";
