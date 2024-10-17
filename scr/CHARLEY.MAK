# Microsoft Visual C++ generated build script - Do not modify

PROJ = CHARLEY
DEBUG = 1
PROGTYPE = 6
CALLER = 
ARGS = 
DLLS = 
D_RCDEFINES = -d_DEBUG
R_RCDEFINES = -dNDEBUG
ORIGIN = MSVC
ORIGIN_VER = 1.00
PROJPATH = C:\UNIX\CHARLEY\
USEMFC = 1
CC = cl
CPP = cl
CXX = cl
CCREATEPCHFLAG = 
CPPCREATEPCHFLAG = 
CUSEPCHFLAG = 
CPPUSEPCHFLAG = 
FIRSTC = ADDCNREC.C  
FIRSTCPP =             
RC = rc
CFLAGS_D_DEXE = /nologo /Zr /G2 /Gy /W4 /Zi /AL /Od /D "_DEBUG" /D "_DOS" /D "DEBUG_MEM" /FR /Fd"CHARLEY.PDB"
CFLAGS_R_DEXE = /nologo /Gs /G3 /W3 /AL /Ot /D "NDEBUG" /D "_DOS" /FR 
LFLAGS_D_DEXE = /NOLOGO /NOI /STACK:30000 /ONERROR:NOEXE /CO 
LFLAGS_R_DEXE = /NOLOGO /NOI /STACK:10000 /ONERROR:NOEXE 
LIBS_D_DEXE = lafxcrd oldnames llibce 
LIBS_R_DEXE = lafxcr oldnames llibce 
RCFLAGS = /nologo
RESFLAGS = /nologo
RUNFLAGS = 
OBJS_EXT = 
LIBS_EXT = 
!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS_D_DEXE)
LFLAGS = $(LFLAGS_D_DEXE)
LIBS = $(LIBS_D_DEXE)
MAPFILE = nul
RCDEFINES = $(D_RCDEFINES)
!else
CFLAGS = $(CFLAGS_R_DEXE)
LFLAGS = $(LFLAGS_R_DEXE)
LIBS = $(LIBS_R_DEXE)
MAPFILE = nul
RCDEFINES = $(R_RCDEFINES)
!endif
!if [if exist MSVC.BND del MSVC.BND]
!endif
SBRS = ADDCNREC.SBR \
		ADDLINK.SBR \
		ADDNODE.SBR \
		ADDRTLNK.SBR \
		ADDRTREC.SBR \
		ADDTRAFF.SBR \
		CHARINIT.SBR \
		CHARLEY.SBR \
		CHKARGS.SBR \
		CNTLINKS.SBR \
		CONRECCD.SBR \
		CONTIVIT.SBR \
		COPYLINK.SBR \
		COPYNET.SBR \
		COST.SBR \
		CPYRLINK.SBR \
		DELAY.SBR \
		DELCNREC.SBR \
		DELLINKS.SBR \
		DELNODES.SBR \
		DELRTLKS.SBR \
		DELRTREC.SBR \
		DELTRAFF.SBR \
		DUP_LINK.SBR \
		DUPSTR.SBR \
		EVOLVE.SBR \
		FEXIST.SBR \
		FILENAME.SBR \
		FINDBEST.SBR \
		FINDNODE.SBR \
		FINDRREC.SBR \
		FITNESS.SBR \
		INC_BUFF.SBR \
		INIVALUE.SBR \
		LINKCD.SBR \
		LOGGER.SBR \
		MATE.SBR \
		MKLINKS.SBR \
		MKNET.SBR \
		MKNODES.SBR \
		MKPOP.SBR \
		MKTRAFF.SBR \
		NETCD.SBR \
		NETPARCD.SBR \
		NODECD.SBR \
		POPCD.SBR \
		PRNCNREC.SBR \
		PRNLINKS.SBR \
		PRNNET.SBR \
		PRNNODES.SBR \
		PRNNTPAR.SBR \
		PRNPOP.SBR \
		PRNRLINK.SBR \
		PRNRTREC.SBR \
		PRNTRAFF.SBR \
		RANDCOST.SBR \
		RANDLINK.SBR \
		RANDMESS.SBR \
		RANDMSLN.SBR \
		RANDNODE.SBR \
		RANDNUM.SBR \
		RANDSPED.SBR \
		READ_LN.SBR \
		RESTLINK.SBR \
		RESTNODE.SBR \
		ROUTECD.SBR \
		ROUTES.SBR \
		RTLINKCD.SBR \
		SELLINK.SBR \
		TRAFFCD.SBR


ADDCNREC_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


ADDLINK_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


ADDNODE_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


ADDRTLNK_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


ADDRTREC_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


ADDTRAFF_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


CHARINIT_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


CHARLEY_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


CHKARGS_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


CNTLINKS_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


CONRECCD_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


CONTIVIT_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


COPYLINK_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


COPYNET_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


COST_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


CPYRLINK_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


DELAY_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


DELCNREC_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


DELLINKS_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


DELNODES_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


DELRTLKS_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


DELRTREC_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


DELTRAFF_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


DUP_LINK_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


DUPSTR_DEP = 

EVOLVE_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


FEXIST_DEP = 

FILENAME_DEP = 

FINDBEST_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


FINDNODE_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


FINDRREC_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


FITNESS_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


INC_BUFF_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


INIVALUE_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


LINKCD_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


LOGGER_DEP = 

MATE_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


MKLINKS_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


MKNET_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


MKNODES_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


MKPOP_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


MKTRAFF_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


NETCD_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


NETPARCD_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


NODECD_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


POPCD_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


PRNCNREC_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


PRNLINKS_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


PRNNET_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


PRNNODES_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


PRNNTPAR_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


PRNPOP_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


PRNRLINK_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


PRNRTREC_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


PRNTRAFF_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


RANDCOST_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


RANDLINK_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


RANDMESS_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


RANDMSLN_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


RANDNODE_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


RANDNUM_DEP = 

RANDSPED_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


READ_LN_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


RESTLINK_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


RESTNODE_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


ROUTECD_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


ROUTES_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


RTLINKCD_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


SELLINK_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


TRAFFCD_DEP = c:\unix\charley\network.h \
	c:\unix\charley\typedef.h \
	c:\unix\charley\nodes.h \
	c:\unix\charley\traffic.h \
	c:\unix\charley\links.h \
	c:\unix\charley\contivit.h \
	c:\unix\charley\routes.h \
	c:\unix\charley\rtlinks.h \
	c:\unix\charley\netparam.h \
	c:\unix\charley\pop.h \
	c:\unix\charley\net.h


all:	$(PROJ).EXE $(PROJ).BSC

ADDCNREC.OBJ:	ADDCNREC.C $(ADDCNREC_DEP)
	$(CC) $(CFLAGS) $(CCREATEPCHFLAG) /c ADDCNREC.C

ADDLINK.OBJ:	ADDLINK.C $(ADDLINK_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c ADDLINK.C

ADDNODE.OBJ:	ADDNODE.C $(ADDNODE_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c ADDNODE.C

ADDRTLNK.OBJ:	ADDRTLNK.C $(ADDRTLNK_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c ADDRTLNK.C

ADDRTREC.OBJ:	ADDRTREC.C $(ADDRTREC_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c ADDRTREC.C

ADDTRAFF.OBJ:	ADDTRAFF.C $(ADDTRAFF_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c ADDTRAFF.C

CHARINIT.OBJ:	CHARINIT.C $(CHARINIT_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c CHARINIT.C

CHARLEY.OBJ:	CHARLEY.C $(CHARLEY_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c CHARLEY.C

CHKARGS.OBJ:	CHKARGS.C $(CHKARGS_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c CHKARGS.C

CNTLINKS.OBJ:	CNTLINKS.C $(CNTLINKS_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c CNTLINKS.C

CONRECCD.OBJ:	CONRECCD.C $(CONRECCD_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c CONRECCD.C

CONTIVIT.OBJ:	CONTIVIT.C $(CONTIVIT_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c CONTIVIT.C

COPYLINK.OBJ:	COPYLINK.C $(COPYLINK_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c COPYLINK.C

COPYNET.OBJ:	COPYNET.C $(COPYNET_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c COPYNET.C

COST.OBJ:	COST.C $(COST_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c COST.C

CPYRLINK.OBJ:	CPYRLINK.C $(CPYRLINK_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c CPYRLINK.C

DELAY.OBJ:	DELAY.C $(DELAY_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c DELAY.C

DELCNREC.OBJ:	DELCNREC.C $(DELCNREC_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c DELCNREC.C

DELLINKS.OBJ:	DELLINKS.C $(DELLINKS_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c DELLINKS.C

DELNODES.OBJ:	DELNODES.C $(DELNODES_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c DELNODES.C

DELRTLKS.OBJ:	DELRTLKS.C $(DELRTLKS_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c DELRTLKS.C

DELRTREC.OBJ:	DELRTREC.C $(DELRTREC_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c DELRTREC.C

DELTRAFF.OBJ:	DELTRAFF.C $(DELTRAFF_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c DELTRAFF.C

DUP_LINK.OBJ:	DUP_LINK.C $(DUP_LINK_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c DUP_LINK.C

DUPSTR.OBJ:	DUPSTR.C $(DUPSTR_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c DUPSTR.C

EVOLVE.OBJ:	EVOLVE.C $(EVOLVE_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c EVOLVE.C

FEXIST.OBJ:	FEXIST.C $(FEXIST_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c FEXIST.C

FILENAME.OBJ:	FILENAME.C $(FILENAME_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c FILENAME.C

FINDBEST.OBJ:	FINDBEST.C $(FINDBEST_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c FINDBEST.C

FINDNODE.OBJ:	FINDNODE.C $(FINDNODE_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c FINDNODE.C

FINDRREC.OBJ:	FINDRREC.C $(FINDRREC_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c FINDRREC.C

FITNESS.OBJ:	FITNESS.C $(FITNESS_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c FITNESS.C

INC_BUFF.OBJ:	INC_BUFF.C $(INC_BUFF_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c INC_BUFF.C

INIVALUE.OBJ:	INIVALUE.C $(INIVALUE_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c INIVALUE.C

LINKCD.OBJ:	LINKCD.C $(LINKCD_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c LINKCD.C

LOGGER.OBJ:	LOGGER.C $(LOGGER_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c LOGGER.C

MATE.OBJ:	MATE.C $(MATE_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c MATE.C

MKLINKS.OBJ:	MKLINKS.C $(MKLINKS_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c MKLINKS.C

MKNET.OBJ:	MKNET.C $(MKNET_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c MKNET.C

MKNODES.OBJ:	MKNODES.C $(MKNODES_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c MKNODES.C

MKPOP.OBJ:	MKPOP.C $(MKPOP_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c MKPOP.C

MKTRAFF.OBJ:	MKTRAFF.C $(MKTRAFF_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c MKTRAFF.C

NETCD.OBJ:	NETCD.C $(NETCD_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c NETCD.C

NETPARCD.OBJ:	NETPARCD.C $(NETPARCD_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c NETPARCD.C

NODECD.OBJ:	NODECD.C $(NODECD_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c NODECD.C

POPCD.OBJ:	POPCD.C $(POPCD_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c POPCD.C

PRNCNREC.OBJ:	PRNCNREC.C $(PRNCNREC_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c PRNCNREC.C

PRNLINKS.OBJ:	PRNLINKS.C $(PRNLINKS_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c PRNLINKS.C

PRNNET.OBJ:	PRNNET.C $(PRNNET_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c PRNNET.C

PRNNODES.OBJ:	PRNNODES.C $(PRNNODES_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c PRNNODES.C

PRNNTPAR.OBJ:	PRNNTPAR.C $(PRNNTPAR_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c PRNNTPAR.C

PRNPOP.OBJ:	PRNPOP.C $(PRNPOP_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c PRNPOP.C

PRNRLINK.OBJ:	PRNRLINK.C $(PRNRLINK_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c PRNRLINK.C

PRNRTREC.OBJ:	PRNRTREC.C $(PRNRTREC_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c PRNRTREC.C

PRNTRAFF.OBJ:	PRNTRAFF.C $(PRNTRAFF_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c PRNTRAFF.C

RANDCOST.OBJ:	RANDCOST.C $(RANDCOST_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c RANDCOST.C

RANDLINK.OBJ:	RANDLINK.C $(RANDLINK_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c RANDLINK.C

RANDMESS.OBJ:	RANDMESS.C $(RANDMESS_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c RANDMESS.C

RANDMSLN.OBJ:	RANDMSLN.C $(RANDMSLN_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c RANDMSLN.C

RANDNODE.OBJ:	RANDNODE.C $(RANDNODE_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c RANDNODE.C

RANDNUM.OBJ:	RANDNUM.C $(RANDNUM_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c RANDNUM.C

RANDSPED.OBJ:	RANDSPED.C $(RANDSPED_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c RANDSPED.C

READ_LN.OBJ:	READ_LN.C $(READ_LN_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c READ_LN.C

RESTLINK.OBJ:	RESTLINK.C $(RESTLINK_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c RESTLINK.C

RESTNODE.OBJ:	RESTNODE.C $(RESTNODE_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c RESTNODE.C

ROUTECD.OBJ:	ROUTECD.C $(ROUTECD_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c ROUTECD.C

ROUTES.OBJ:	ROUTES.C $(ROUTES_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c ROUTES.C

RTLINKCD.OBJ:	RTLINKCD.C $(RTLINKCD_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c RTLINKCD.C

SELLINK.OBJ:	SELLINK.C $(SELLINK_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c SELLINK.C

TRAFFCD.OBJ:	TRAFFCD.C $(TRAFFCD_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c TRAFFCD.C

$(PROJ).EXE::	ADDCNREC.OBJ ADDLINK.OBJ ADDNODE.OBJ ADDRTLNK.OBJ ADDRTREC.OBJ ADDTRAFF.OBJ \
	CHARINIT.OBJ CHARLEY.OBJ CHKARGS.OBJ CNTLINKS.OBJ CONRECCD.OBJ CONTIVIT.OBJ COPYLINK.OBJ \
	COPYNET.OBJ COST.OBJ CPYRLINK.OBJ DELAY.OBJ DELCNREC.OBJ DELLINKS.OBJ DELNODES.OBJ \
	DELRTLKS.OBJ DELRTREC.OBJ DELTRAFF.OBJ DUP_LINK.OBJ DUPSTR.OBJ EVOLVE.OBJ FEXIST.OBJ \
	FILENAME.OBJ FINDBEST.OBJ FINDNODE.OBJ FINDRREC.OBJ FITNESS.OBJ INC_BUFF.OBJ INIVALUE.OBJ \
	LINKCD.OBJ LOGGER.OBJ MATE.OBJ MKLINKS.OBJ MKNET.OBJ MKNODES.OBJ MKPOP.OBJ MKTRAFF.OBJ \
	NETCD.OBJ NETPARCD.OBJ NODECD.OBJ POPCD.OBJ PRNCNREC.OBJ PRNLINKS.OBJ PRNNET.OBJ \
	PRNNODES.OBJ PRNNTPAR.OBJ PRNPOP.OBJ PRNRLINK.OBJ PRNRTREC.OBJ PRNTRAFF.OBJ RANDCOST.OBJ \
	RANDLINK.OBJ RANDMESS.OBJ RANDMSLN.OBJ RANDNODE.OBJ RANDNUM.OBJ RANDSPED.OBJ READ_LN.OBJ \
	RESTLINK.OBJ RESTNODE.OBJ ROUTECD.OBJ ROUTES.OBJ RTLINKCD.OBJ SELLINK.OBJ TRAFFCD.OBJ $(OBJS_EXT) $(DEFFILE)
	echo >NUL @<<$(PROJ).CRF
ADDCNREC.OBJ +
ADDLINK.OBJ +
ADDNODE.OBJ +
ADDRTLNK.OBJ +
ADDRTREC.OBJ +
ADDTRAFF.OBJ +
CHARINIT.OBJ +
CHARLEY.OBJ +
CHKARGS.OBJ +
CNTLINKS.OBJ +
CONRECCD.OBJ +
CONTIVIT.OBJ +
COPYLINK.OBJ +
COPYNET.OBJ +
COST.OBJ +
CPYRLINK.OBJ +
DELAY.OBJ +
DELCNREC.OBJ +
DELLINKS.OBJ +
DELNODES.OBJ +
DELRTLKS.OBJ +
DELRTREC.OBJ +
DELTRAFF.OBJ +
DUP_LINK.OBJ +
DUPSTR.OBJ +
EVOLVE.OBJ +
FEXIST.OBJ +
FILENAME.OBJ +
FINDBEST.OBJ +
FINDNODE.OBJ +
FINDRREC.OBJ +
FITNESS.OBJ +
INC_BUFF.OBJ +
INIVALUE.OBJ +
LINKCD.OBJ +
LOGGER.OBJ +
MATE.OBJ +
MKLINKS.OBJ +
MKNET.OBJ +
MKNODES.OBJ +
MKPOP.OBJ +
MKTRAFF.OBJ +
NETCD.OBJ +
NETPARCD.OBJ +
NODECD.OBJ +
POPCD.OBJ +
PRNCNREC.OBJ +
PRNLINKS.OBJ +
PRNNET.OBJ +
PRNNODES.OBJ +
PRNNTPAR.OBJ +
PRNPOP.OBJ +
PRNRLINK.OBJ +
PRNRTREC.OBJ +
PRNTRAFF.OBJ +
RANDCOST.OBJ +
RANDLINK.OBJ +
RANDMESS.OBJ +
RANDMSLN.OBJ +
RANDNODE.OBJ +
RANDNUM.OBJ +
RANDSPED.OBJ +
READ_LN.OBJ +
RESTLINK.OBJ +
RESTNODE.OBJ +
ROUTECD.OBJ +
ROUTES.OBJ +
RTLINKCD.OBJ +
SELLINK.OBJ +
TRAFFCD.OBJ +
$(OBJS_EXT)
$(PROJ).EXE
$(MAPFILE)
c:\apps\msvc\lib\+
c:\apps\msvc\mfc\lib\+
$(LIBS)
$(DEFFILE);
<<
	link $(LFLAGS) @$(PROJ).CRF

run: $(PROJ).EXE
	$(PROJ) $(RUNFLAGS)


$(PROJ).BSC: $(SBRS)
	bscmake @<<
/o$@ $(SBRS)
<<
