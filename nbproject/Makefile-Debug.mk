#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/QuadTree.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=../../c++/SFML-2.1/lib/libsfml-graphics.so ../../c++/SFML-2.1/lib/libsfml-system.so ../../c++/SFML-2.1/lib/libsfml-window.so `pkg-config --libs gl` `pkg-config --libs glew`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/quadtreevoxels

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/quadtreevoxels: ../../c++/SFML-2.1/lib/libsfml-graphics.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/quadtreevoxels: ../../c++/SFML-2.1/lib/libsfml-system.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/quadtreevoxels: ../../c++/SFML-2.1/lib/libsfml-window.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/quadtreevoxels: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/quadtreevoxels ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/QuadTree.o: QuadTree.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../c++/SFML-2.1/include `pkg-config --cflags gl` `pkg-config --cflags glew` -std=c++11  -MMD -MP -MF $@.d -o ${OBJECTDIR}/QuadTree.o QuadTree.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../c++/SFML-2.1/include `pkg-config --cflags gl` `pkg-config --cflags glew` -std=c++11  -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/quadtreevoxels

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
