// winprc.h

#ifndef _WINPRC_H_INCLUDED_
#define _WINPRC_H_INCLUDED_

#include <Windows.h>
#include <string>
#include "resource.h"
#include "abtd.h"
#include "print.h"


// Character constants
constexpr char nullterminator = '\0';
const std::string separator{ "\r\n" };
const std::string emptyString{ "" };
const std::string editName{ "EDIT" };

// Default dimensions for main edit control
constexpr unsigned int xPos   = 0;
constexpr unsigned int yPos   = 0;
constexpr unsigned int width  = 100;
constexpr unsigned int height = 100;

// The Main Window Procedure
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Creates an edit control for the main app window
//void create_edit_control(HWND, HWND);

// Ensures the proper sizing of the edit control
//void size_edit_control(HWND, HWND);

// Opens a text file and reads it into memory
void create_openfile_dlg(const HWND, const HWND);

// Read from a text file
BOOL LoadTextFileToEdit(const HWND, const OPENFILENAME&);

// Creates the 'About' dialog box
void create_about_dialog(const HWND);
#endif // !_WINPRC_H_INCLUDED_
