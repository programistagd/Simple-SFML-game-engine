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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Edible.o \
	${OBJECTDIR}/GameObject.o \
	${OBJECTDIR}/GameWorld.o \
	${OBJECTDIR}/LevelSwitch.o \
	${OBJECTDIR}/Observer.o \
	${OBJECTDIR}/Obstacle.o \
	${OBJECTDIR}/Player.o \
	${OBJECTDIR}/ResourceManager.o \
	${OBJECTDIR}/StaticObject.o \
	${OBJECTDIR}/TextSign.o \
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
LDLIBSOPTIONS=../../c++/SFML-2.1/lib/libsfml-graphics.so ../../c++/SFML-2.1/lib/libsfml-system.so ../../c++/SFML-2.1/lib/libsfml-window.so

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ppgame

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ppgame: ../../c++/SFML-2.1/lib/libsfml-graphics.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ppgame: ../../c++/SFML-2.1/lib/libsfml-system.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ppgame: ../../c++/SFML-2.1/lib/libsfml-window.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ppgame: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ppgame ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Edible.o: Edible.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../c++/SFML-2.1/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Edible.o Edible.cpp

${OBJECTDIR}/GameObject.o: GameObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../c++/SFML-2.1/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GameObject.o GameObject.cpp

${OBJECTDIR}/GameWorld.o: GameWorld.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../c++/SFML-2.1/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GameWorld.o GameWorld.cpp

${OBJECTDIR}/LevelSwitch.o: LevelSwitch.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../c++/SFML-2.1/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/LevelSwitch.o LevelSwitch.cpp

${OBJECTDIR}/Observer.o: Observer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../c++/SFML-2.1/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Observer.o Observer.cpp

${OBJECTDIR}/Obstacle.o: Obstacle.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../c++/SFML-2.1/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Obstacle.o Obstacle.cpp

${OBJECTDIR}/Player.o: Player.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../c++/SFML-2.1/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Player.o Player.cpp

${OBJECTDIR}/ResourceManager.o: ResourceManager.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../c++/SFML-2.1/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/ResourceManager.o ResourceManager.cpp

${OBJECTDIR}/StaticObject.o: StaticObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../c++/SFML-2.1/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/StaticObject.o StaticObject.cpp

${OBJECTDIR}/TextSign.o: TextSign.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../c++/SFML-2.1/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/TextSign.o TextSign.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../../c++/SFML-2.1/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ppgame

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
