#include <wx/wx.h> 
#include <wx/notebook.h> 
#include <wx/busyinfo.h>

#define MODIFY_MENU					1
#define MODIFY_PANEL				1

typedef unsigned char   TYuint8;	/* Integer 8 Bit (unsigned) */
typedef unsigned short  TYuint16;	/* Integer 18 Bit (unsigned) */
typedef unsigned long   TYuint32;	/* Integer 32 Bit (unsigned) */

typedef unsigned char 	TYbyte;         /* 1 Byte ( 8 Bit), unsigned  */ 
typedef unsigned short 	TYword;         /* 1 Word (16 Bit), unsigned  */ 
typedef unsigned long 	TYlong;         /* 1 Long (32 Bit), unsigned  */ 

typedef unsigned char 	TYmask8;        /* 1 Byte ( 8 Bit), unsigned  */ 
typedef unsigned short 	TYmask16;       /* 1 Word (16 Bit), unsigned  */ 
typedef unsigned long 	TYmask32;       /* 1 Long (32 Bit), unsigned  */ 

typedef char          	TYstr;		/* String */
typedef char*          	TYstrPtr;	/* Ptr. auf String */
typedef char          	TYstrBuf;	/* String-Buffer */

typedef struct 
{ 
    short left;		/* linke  x-Koordinate */
    short top;		/* obere  y-Koordinate */
    short right;	/* rechte x-Koordinate */
    short bottom;	/* untere y-Koordinate */

} TYsysRect;		/* Rechteck-Objekt */

typedef	TYuint16 TYerrno;		/* Datentyp 'Fehler'         */

typedef struct
{
    TYuint8 aktConVal;		/* aktueller Kontrast */
    TYuint8 defConVal;		/* Default-Kontrast */
    TYuint8 minConVal;		/* minimaler Kontrast */
    TYuint8 maxConVal;		/* maximaler Kontrast */
    TYuint8 deltaConVal;	/* Kontrast-Schrittweite */
    
    TYuint8 aktLumVal;		/* aktuelle Helligkeit */
    TYuint8 defLumVal;		/* Default-Helligkeit */
    TYuint8 minLumVal;		/* minimale Helligkeit */
    TYuint8 maxLumVal;		/* maximaler Helligkeit */
    TYuint8 deltaLumVal;	/* Helligkeit-Schrittweite */

    short width;		/* Breite in Pixel */
    short height;		/* Hoehe in Pixel */
    void *base;			/* Ptr. auf Bildspeicher */
    short type;			/* Type */

    TYsysRect localRect;
    TYsysRect globalRect;

    TYerrno sts;
    TYmask8 eor;

    TYstr   name[32];

} TYsysDisplay;

class CKroemApp : public wxApp
{
    bool OnInit();
};

class CKroemFrame : public wxFrame
{
public:
	CKroemFrame(wxWindow *parent,
				wxWindowID id,
				const wxString& title);
	CKroemFrame(wxPoint pos, float sizeFactorH, float sizeFactorW);
public:

	// any class wishing to process wxWidgets events must use this macro
    DECLARE_EVENT_TABLE()
	//Show
	// On Paint Methode
    void OnPaint(wxPaintEvent & WXUNUSED (event));
    void OnEraseBackground(wxEraseEvent& WXUNUSED(event));
	void OnShow(wxShowEvent& event);
	//Mouse
	void OnMouseEvent(wxMouseEvent& event);
	wxDateTime m_TimeMouseLeftDown;
public:
#if defined( MODIFY_PANEL )
	wxNotebook    *m_book;
#endif
};

