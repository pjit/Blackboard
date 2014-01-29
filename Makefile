#############################################################################
# Makefile for building: BlackBoard.app/Contents/MacOS/BlackBoard
# Generated by qmake (2.01a) (Qt 4.8.0) on: Sat Sep 15 00:29:35 2012
# Project:  BlackBoard.pro
# Template: app
# Command: /Users/iManna/Documents/Development/qt/Desktop/Qt/4.8.0/gcc/bin/qmake -o Makefile BlackBoard.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DdDOUBLE
CFLAGS        = -pipe -g -gdwarf-2 -arch x86_64 -Xarch_x86_64 -mmacosx-version-min=10.5 -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -g -gdwarf-2 -arch x86_64 -Xarch_x86_64 -mmacosx-version-min=10.5 -Wall -W $(DEFINES)
INCPATH       = -I../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/default -I. -I../../Qt/Desktop/Qt/4.8.0/gcc/lib/QtCore.framework/Versions/4/Headers \
		    -I../../Qt/Desktop/Qt/4.8.0/gcc/include/QtCore -I../../Qt/Desktop/Qt/4.8.0/gcc/lib/QtGui.framework/Versions/4/Headers \
		    -I../../Qt/Desktop/Qt/4.8.0/gcc/include/QtGui -I../../Qt/Desktop/Qt/4.8.0/gcc/include -I. -Isrc -I. \
		    -F/Users/iManna/Documents/Development/Qt/Desktop/Qt/4.8.0/gcc/lib \
		    -I/usr/local/ode/include
LINK          = g++
LFLAGS        = -headerpad_max_install_names -arch x86_64 -Xarch_x86_64 -mmacosx-version-min=10.5
LIBS          = $(SUBLIBS) -F/Users/iManna/Documents/Development/Qt/Desktop/Qt/4.8.0/gcc/lib \
		    -L/Users/iManna/Documents/Development/Qt/Desktop/Qt/4.8.0/gcc/lib -framework QtGui -framework QtCore \
		    -L/usr/local/ode/lib -lode \
		    -L/System/Library/Frameworks/OpenGL.framework/Libraries -framework OpenGL -framework QtOpenGL
AR            = ar cq
RANLIB        = ranlib -s
QMAKE         = /Users/iManna/Documents/Development/qt/Desktop/Qt/4.8.0/gcc/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
STRIP         = 
INSTALL_FILE  = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = $(COPY_FILE)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
export MACOSX_DEPLOYMENT_TARGET = 10.4

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = src/BlackBoard.cpp \
		src/BlackBoardApp.cpp \
		src/BlackBoardPanel.cpp \
		src/BlackBoardPanelScene.cpp \
		src/Board.cpp \
		src/BoardBody.cpp \
		src/BoardBox.cpp \
		src/BoardCmds.cpp \
		src/BoardItem.cpp \
		src/BoardModel.cpp \
		src/BoardModelDelegate.cpp \
		src/BoardPanel.cpp \
		src/BoardPanelCmds.cpp \
		src/BoardScene.cpp \
		src/BoardStrip.cpp \
		src/BoardView.cpp \
		src/Cmd.cpp \
		src/CmdArg.cpp \
		src/CmdManager.cpp \
		src/CmdWindow.cpp \
		src/ContentPanel.cpp \
		src/HierarchyView.cpp \
		src/MainPanel.cpp \
		src/ObjectPanel.cpp \
		src/PrefManager.cpp \
		src/PropertyItem.cpp \
		src/PropertyModel.cpp \
		src/PropertyView.cpp \
		src/TabBarPanel.cpp \
		src/ToolBoxView.cpp \
		src/Utility.cpp moc_BlackBoardApp.cpp \
		moc_BlackBoardPanel.cpp \
		moc_BlackBoardPanelScene.cpp \
		moc_Board.cpp \
		moc_BoardPanel.cpp \
		moc_BoardScene.cpp \
		moc_BoardStrip.cpp \
		moc_BoardView.cpp \
		moc_CmdWindow.cpp \
		moc_ContentPanel.cpp \
		moc_HierarchyView.cpp \
		moc_MainPanel.cpp \
		moc_ObjectPanel.cpp \
		moc_PropertyView.cpp \
		moc_TabBarPanel.cpp \
		moc_ToolBoxView.cpp \
		qrc_BlackBoard.cpp
OBJECTS       = BlackBoard.o \
		BlackBoardApp.o \
		BlackBoardPanel.o \
		BlackBoardPanelScene.o \
		Board.o \
		BoardBody.o \
		BoardBox.o \
		BoardCmds.o \
		BoardItem.o \
		BoardModel.o \
		BoardModelDelegate.o \
		BoardPanel.o \
		BoardPanelCmds.o \
		BoardScene.o \
		BoardStrip.o \
		BoardView.o \
		Cmd.o \
		CmdArg.o \
		CmdManager.o \
		CmdWindow.o \
		ContentPanel.o \
		HierarchyView.o \
		MainPanel.o \
		ObjectPanel.o \
		PrefManager.o \
		PropertyItem.o \
		PropertyModel.o \
		PropertyView.o \
		TabBarPanel.o \
		ToolBoxView.o \
		Utility.o \
		moc_BlackBoardApp.o \
		moc_BlackBoardPanel.o \
		moc_BlackBoardPanelScene.o \
		moc_Board.o \
		moc_BoardPanel.o \
		moc_BoardScene.o \
		moc_BoardStrip.o \
		moc_BoardView.o \
		moc_CmdWindow.o \
		moc_ContentPanel.o \
		moc_HierarchyView.o \
		moc_MainPanel.o \
		moc_ObjectPanel.o \
		moc_PropertyView.o \
		moc_TabBarPanel.o \
		moc_ToolBoxView.o \
		qrc_BlackBoard.o
DIST          = ../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/common/unix.conf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/common/mac.conf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/common/gcc-base.conf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/common/gcc-base-macx.conf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/common/g++-base.conf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/common/g++-macx.conf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/qconfig.pri \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/modules/qt_webkit_version.pri \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/qt_functions.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/qt_config.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/exclusive_builds.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/default_pre.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/mac/default_pre.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/mac/dwarf2.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/debug.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/default_post.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/mac/default_post.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/mac/x86_64.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/mac/objective_c.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/warn_on.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/qt.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/unix/thread.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/moc.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/mac/rez.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/mac/sdk.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/resources.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/uic.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/yacc.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/lex.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/include_source_dir.prf \
		BlackBoard.pro
QMAKE_TARGET  = BlackBoard
DESTDIR       = 
TARGET        = BlackBoard.app/Contents/MacOS/BlackBoard

####### Custom Compiler Variables
QMAKE_COMP_QMAKE_OBJECTIVE_CFLAGS = -pipe \
		-g \
		-arch \
		x86_64 \
		-Xarch_x86_64 \
		-mmacosx-version-min=10.5 \
		-Wall \
		-W


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile BlackBoard.app/Contents/PkgInfo BlackBoard.app/Contents/Resources/empty.lproj BlackBoard.app/Contents/Info.plist $(TARGET)

$(TARGET):  $(OBJECTS)  
	@$(CHK_DIR_EXISTS) BlackBoard.app/Contents/MacOS/ || $(MKDIR) BlackBoard.app/Contents/MacOS/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: BlackBoard.pro  ../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/default/qmake.conf ../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/common/unix.conf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/common/mac.conf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/common/gcc-base.conf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/common/gcc-base-macx.conf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/common/g++-base.conf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/common/g++-macx.conf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/qconfig.pri \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/modules/qt_webkit_version.pri \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/qt_functions.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/qt_config.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/exclusive_builds.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/default_pre.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/mac/default_pre.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/mac/dwarf2.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/debug.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/default_post.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/mac/default_post.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/mac/x86_64.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/mac/objective_c.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/warn_on.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/qt.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/unix/thread.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/moc.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/mac/rez.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/mac/sdk.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/resources.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/uic.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/yacc.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/lex.prf \
		../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/include_source_dir.prf
	$(QMAKE) -o Makefile BlackBoard.pro
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/common/unix.conf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/common/mac.conf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/common/gcc-base.conf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/common/gcc-base-macx.conf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/common/g++-base.conf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/common/g++-macx.conf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/qconfig.pri:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/modules/qt_webkit_version.pri:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/qt_functions.prf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/qt_config.prf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/exclusive_builds.prf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/default_pre.prf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/mac/default_pre.prf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/mac/dwarf2.prf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/debug.prf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/default_post.prf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/mac/default_post.prf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/mac/x86_64.prf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/mac/objective_c.prf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/warn_on.prf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/qt.prf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/unix/thread.prf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/moc.prf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/mac/rez.prf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/mac/sdk.prf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/resources.prf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/uic.prf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/yacc.prf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/lex.prf:
../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/features/include_source_dir.prf:
qmake:  FORCE
	@$(QMAKE) -o Makefile BlackBoard.pro

BlackBoard.app/Contents/PkgInfo: 
	@$(CHK_DIR_EXISTS) BlackBoard.app/Contents || $(MKDIR) BlackBoard.app/Contents 
	@$(DEL_FILE) BlackBoard.app/Contents/PkgInfo
	@echo "APPL????" >BlackBoard.app/Contents/PkgInfo
BlackBoard.app/Contents/Resources/empty.lproj: 
	@$(CHK_DIR_EXISTS) BlackBoard.app/Contents/Resources || $(MKDIR) BlackBoard.app/Contents/Resources 
	@touch BlackBoard.app/Contents/Resources/empty.lproj
	
BlackBoard.app/Contents/Info.plist: 
	@$(CHK_DIR_EXISTS) BlackBoard.app/Contents || $(MKDIR) BlackBoard.app/Contents 
	@$(DEL_FILE) BlackBoard.app/Contents/Info.plist
	@sed -e "s,@SHORT_VERSION@,1.0,g" -e "s,@TYPEINFO@,????,g" -e "s,@ICON@,,g" -e "s,@EXECUTABLE@,BlackBoard,g" -e "s,@TYPEINFO@,????,g" ../../Qt/Desktop/Qt/4.8.0/gcc/mkspecs/default/Info.plist.app >BlackBoard.app/Contents/Info.plist
dist: 
	@$(CHK_DIR_EXISTS) .tmp/BlackBoard1.0.0 || $(MKDIR) .tmp/BlackBoard1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/BlackBoard1.0.0/ && $(COPY_FILE) --parents src/BlackBoard.h src/BlackBoardApp.h src/BlackBoardPanel.h src/BlackBoardPanelScene.h src/Board.h src/BoardBody.h src/BoardBox.h src/BoardCmds.h src/BoardItem.h src/BoardModel.h src/BoardModelDelegate.h src/BoardPanel.h src/BoardPanelCmds.h src/BoardScene.h src/BoardStrip.h src/BoardView.h src/Cmd.h src/CmdArg.h src/CmdManager.h src/CmdWindow.h src/ContentPanel.h src/HierarchyView.h src/MainPanel.h src/ObjectPanel.h src/PrefManager.h src/PropertyItem.h src/PropertyModel.h src/PropertyView.h src/TabBarPanel.h src/targetver.h src/ToolBoxView.h src/Utility.h src/BlackBoardApp.moc src/BlackBoardPanel.moc src/BlackBoardPanelScene.moc src/Board.moc src/BoardPanel.moc src/BoardScene.moc src/BoardStrip.moc src/BoardView.moc src/CmdWindow.moc src/ContentPanel.moc src/HierarchyView.moc src/MainPanel.moc src/ObjectPanel.moc src/PropertyView.moc src/TabBarPanel.moc src/ToolBoxView.moc .tmp/BlackBoard1.0.0/ && $(COPY_FILE) --parents src/BlackBoard.qrc .tmp/BlackBoard1.0.0/ && $(COPY_FILE) --parents src/BlackBoard.cpp src/BlackBoardApp.cpp src/BlackBoardPanel.cpp src/BlackBoardPanelScene.cpp src/Board.cpp src/BoardBody.cpp src/BoardBox.cpp src/BoardCmds.cpp src/BoardItem.cpp src/BoardModel.cpp src/BoardModelDelegate.cpp src/BoardPanel.cpp src/BoardPanelCmds.cpp src/BoardScene.cpp src/BoardStrip.cpp src/BoardView.cpp src/Cmd.cpp src/CmdArg.cpp src/CmdManager.cpp src/CmdWindow.cpp src/ContentPanel.cpp src/HierarchyView.cpp src/MainPanel.cpp src/ObjectPanel.cpp src/PrefManager.cpp src/PropertyItem.cpp src/PropertyModel.cpp src/PropertyView.cpp src/TabBarPanel.cpp src/ToolBoxView.cpp src/Utility.cpp .tmp/BlackBoard1.0.0/ && (cd `dirname .tmp/BlackBoard1.0.0` && $(TAR) BlackBoard1.0.0.tar BlackBoard1.0.0 && $(COMPRESS) BlackBoard1.0.0.tar) && $(MOVE) `dirname .tmp/BlackBoard1.0.0`/BlackBoard1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/BlackBoard1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) -r BlackBoard.app
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_moc_header_make_all: moc_BlackBoardApp.cpp moc_BlackBoardPanel.cpp moc_BlackBoardPanelScene.cpp moc_Board.cpp moc_BoardPanel.cpp moc_BoardScene.cpp moc_BoardStrip.cpp moc_BoardView.cpp moc_CmdWindow.cpp moc_ContentPanel.cpp moc_HierarchyView.cpp moc_MainPanel.cpp moc_ObjectPanel.cpp moc_PropertyView.cpp moc_TabBarPanel.cpp moc_ToolBoxView.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_BlackBoardApp.cpp moc_BlackBoardPanel.cpp moc_BlackBoardPanelScene.cpp moc_Board.cpp moc_BoardPanel.cpp moc_BoardScene.cpp moc_BoardStrip.cpp moc_BoardView.cpp moc_CmdWindow.cpp moc_ContentPanel.cpp moc_HierarchyView.cpp moc_MainPanel.cpp moc_ObjectPanel.cpp moc_PropertyView.cpp moc_TabBarPanel.cpp moc_ToolBoxView.cpp
moc_BlackBoardApp.cpp: src/BlackBoard.h \
		src/targetver.h \
		src/BlackBoardApp.h
	/Users/iManna/Documents/Development/Qt/Desktop/Qt/4.8.0/gcc/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/BlackBoardApp.h -o moc_BlackBoardApp.cpp

moc_BlackBoardPanel.cpp: src/BlackBoardPanel.h
	/Users/iManna/Documents/Development/Qt/Desktop/Qt/4.8.0/gcc/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/BlackBoardPanel.h -o moc_BlackBoardPanel.cpp

moc_BlackBoardPanelScene.cpp: src/BlackBoardPanelScene.h
	/Users/iManna/Documents/Development/Qt/Desktop/Qt/4.8.0/gcc/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/BlackBoardPanelScene.h -o moc_BlackBoardPanelScene.cpp

moc_Board.cpp: src/Board.h
	/Users/iManna/Documents/Development/Qt/Desktop/Qt/4.8.0/gcc/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/Board.h -o moc_Board.cpp

moc_BoardPanel.cpp: src/BoardPanel.h
	/Users/iManna/Documents/Development/Qt/Desktop/Qt/4.8.0/gcc/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/BoardPanel.h -o moc_BoardPanel.cpp

moc_BoardScene.cpp: src/Board.h \
		src/BoardScene.h
	/Users/iManna/Documents/Development/Qt/Desktop/Qt/4.8.0/gcc/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/BoardScene.h -o moc_BoardScene.cpp

moc_BoardStrip.cpp: src/BoardStrip.h
	/Users/iManna/Documents/Development/Qt/Desktop/Qt/4.8.0/gcc/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/BoardStrip.h -o moc_BoardStrip.cpp

moc_BoardView.cpp: src/BoardModel.h \
		src/Board.h \
		src/BoardView.h
	/Users/iManna/Documents/Development/Qt/Desktop/Qt/4.8.0/gcc/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/BoardView.h -o moc_BoardView.cpp

moc_CmdWindow.cpp: src/CmdWindow.h
	/Users/iManna/Documents/Development/Qt/Desktop/Qt/4.8.0/gcc/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/CmdWindow.h -o moc_CmdWindow.cpp

moc_ContentPanel.cpp: src/ContentPanel.h
	/Users/iManna/Documents/Development/Qt/Desktop/Qt/4.8.0/gcc/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/ContentPanel.h -o moc_ContentPanel.cpp

moc_HierarchyView.cpp: src/HierarchyView.h
	/Users/iManna/Documents/Development/Qt/Desktop/Qt/4.8.0/gcc/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/HierarchyView.h -o moc_HierarchyView.cpp

moc_MainPanel.cpp: src/MainPanel.h
	/Users/iManna/Documents/Development/Qt/Desktop/Qt/4.8.0/gcc/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/MainPanel.h -o moc_MainPanel.cpp

moc_ObjectPanel.cpp: src/BoardPanel.h \
		src/ObjectPanel.h
	/Users/iManna/Documents/Development/Qt/Desktop/Qt/4.8.0/gcc/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/ObjectPanel.h -o moc_ObjectPanel.cpp

moc_PropertyView.cpp: src/PropertyView.h
	/Users/iManna/Documents/Development/Qt/Desktop/Qt/4.8.0/gcc/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/PropertyView.h -o moc_PropertyView.cpp

moc_TabBarPanel.cpp: src/TabBarPanel.h
	/Users/iManna/Documents/Development/Qt/Desktop/Qt/4.8.0/gcc/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/TabBarPanel.h -o moc_TabBarPanel.cpp

moc_ToolBoxView.cpp: src/ToolBoxView.h
	/Users/iManna/Documents/Development/Qt/Desktop/Qt/4.8.0/gcc/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ src/ToolBoxView.h -o moc_ToolBoxView.cpp

compiler_rcc_make_all: qrc_BlackBoard.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_BlackBoard.cpp
qrc_BlackBoard.cpp: src/BlackBoard.qrc \
		src/images/BBCircle.png
	/Users/iManna/Documents/Development/Qt/Desktop/Qt/4.8.0/gcc/bin/rcc -name BlackBoard src/BlackBoard.qrc -o qrc_BlackBoard.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean 

####### Compile

BlackBoard.o: src/BlackBoard.cpp src/BlackBoardApp.h \
		src/BlackBoard.h \
		src/targetver.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BlackBoard.o src/BlackBoard.cpp

BlackBoardApp.o: src/BlackBoardApp.cpp src/BlackBoardApp.h \
		src/BlackBoard.h \
		src/targetver.h \
		src/MainPanel.h \
		src/PrefManager.h \
		src/BlackBoardApp.moc
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BlackBoardApp.o src/BlackBoardApp.cpp

BlackBoardPanel.o: src/BlackBoardPanel.cpp src/BlackBoardPanel.h \
		src/BlackBoardPanelScene.h \
		src/BlackBoardPanel.moc
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BlackBoardPanel.o src/BlackBoardPanel.cpp

BlackBoardPanelScene.o: src/BlackBoardPanelScene.cpp src/BlackBoardPanelScene.h \
		src/BlackBoardPanelScene.moc
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BlackBoardPanelScene.o src/BlackBoardPanelScene.cpp

Board.o: src/Board.cpp src/Board.h \
		src/Utility.h \
		src/PrefManager.h \
		src/BoardModel.h \
		src/BoardBox.h \
		src/BoardStrip.h \
		src/Board.moc
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Board.o src/Board.cpp

BoardBody.o: src/BoardBody.cpp src/BoardBody.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BoardBody.o src/BoardBody.cpp

BoardBox.o: src/BoardBox.cpp src/BoardBox.h \
		src/BoardBody.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BoardBox.o src/BoardBox.cpp

BoardCmds.o: src/BoardCmds.cpp src/BoardCmds.h \
		src/BoardView.h \
		src/BoardModel.h \
		src/Board.h \
		src/PrefManager.h \
		src/Cmd.h \
		src/CmdArg.h \
		src/BoardItem.h \
		src/BoardBody.h \
		src/BoardBox.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BoardCmds.o src/BoardCmds.cpp

BoardItem.o: src/BoardItem.cpp src/BoardItem.h \
		src/BoardBody.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BoardItem.o src/BoardItem.cpp

BoardModel.o: src/BoardModel.cpp src/BoardModel.h \
		src/BoardItem.h \
		src/BoardBody.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BoardModel.o src/BoardModel.cpp

BoardModelDelegate.o: src/BoardModelDelegate.cpp src/BoardModelDelegate.h \
		src/BoardModel.h \
		src/BoardItem.h \
		src/BoardBody.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BoardModelDelegate.o src/BoardModelDelegate.cpp

BoardPanel.o: src/BoardPanel.cpp src/BoardPanel.h \
		src/BoardView.h \
		src/BoardModel.h \
		src/Board.h \
		src/TabBarPanel.h \
		src/BoardPanelCmds.h \
		src/CmdWindow.h \
		src/Cmd.h \
		src/CmdArg.h \
		src/BoardScene.h \
		src/BoardStrip.h \
		src/BoardPanel.moc
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BoardPanel.o src/BoardPanel.cpp

BoardPanelCmds.o: src/BoardPanelCmds.cpp src/BoardPanelCmds.h \
		src/BoardPanel.h \
		src/PrefManager.h \
		src/Cmd.h \
		src/CmdArg.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BoardPanelCmds.o src/BoardPanelCmds.cpp

BoardScene.o: src/BoardScene.cpp src/BoardScene.h \
		src/Board.h \
		src/BoardScene.moc
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BoardScene.o src/BoardScene.cpp

BoardStrip.o: src/BoardStrip.cpp src/BoardStrip.h \
		src/Cmd.h \
		src/CmdArg.h \
		src/BoardStrip.moc
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BoardStrip.o src/BoardStrip.cpp

BoardView.o: src/BoardView.cpp src/BoardView.h \
		src/BoardModel.h \
		src/Board.h \
		src/Cmd.h \
		src/CmdArg.h \
		src/BoardCmds.h \
		src/BoardScene.h \
		src/BoardStrip.h \
		src/BoardView.moc
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BoardView.o src/BoardView.cpp

Cmd.o: src/Cmd.cpp src/Cmd.h \
		src/CmdArg.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Cmd.o src/Cmd.cpp

CmdArg.o: src/CmdArg.cpp src/CmdArg.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CmdArg.o src/CmdArg.cpp

CmdManager.o: src/CmdManager.cpp src/CmdManager.h \
		src/Cmd.h \
		src/CmdArg.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CmdManager.o src/CmdManager.cpp

CmdWindow.o: src/CmdWindow.cpp src/CmdWindow.h \
		src/CmdManager.h \
		src/Cmd.h \
		src/CmdArg.h \
		src/CmdWindow.moc
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CmdWindow.o src/CmdWindow.cpp

ContentPanel.o: src/ContentPanel.cpp src/ContentPanel.h \
		src/ObjectPanel.h \
		src/BoardPanel.h \
		src/BoardView.h \
		src/BoardModel.h \
		src/Board.h \
		src/BoardItem.h \
		src/BoardBody.h \
		src/BoardBox.h \
		src/ContentPanel.moc
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ContentPanel.o src/ContentPanel.cpp

HierarchyView.o: src/HierarchyView.cpp src/HierarchyView.h \
		src/HierarchyView.moc
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o HierarchyView.o src/HierarchyView.cpp

MainPanel.o: src/MainPanel.cpp src/MainPanel.h \
		src/ContentPanel.h \
		src/BlackBoardPanel.h \
		src/MainPanel.moc
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o MainPanel.o src/MainPanel.cpp

ObjectPanel.o: src/ObjectPanel.cpp src/ObjectPanel.h \
		src/BoardPanel.h \
		src/HierarchyView.h \
		src/PropertyView.h \
		src/PropertyModel.h \
		src/BoardModel.h \
		src/BoardItem.h \
		src/BoardBody.h \
		src/Board.h \
		src/ObjectPanel.moc
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ObjectPanel.o src/ObjectPanel.cpp

PrefManager.o: src/PrefManager.cpp src/PrefManager.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o PrefManager.o src/PrefManager.cpp

PropertyItem.o: src/PropertyItem.cpp src/PropertyItem.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o PropertyItem.o src/PropertyItem.cpp

PropertyModel.o: src/PropertyModel.cpp src/PropertyModel.h \
		src/PropertyItem.h \
		src/BoardItem.h \
		src/BoardBody.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o PropertyModel.o src/PropertyModel.cpp

PropertyView.o: src/PropertyView.cpp src/PropertyView.h \
		src/PropertyView.moc
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o PropertyView.o src/PropertyView.cpp

TabBarPanel.o: src/TabBarPanel.cpp src/TabBarPanel.h \
		src/BoardView.h \
		src/BoardModel.h \
		src/Board.h \
		src/TabBarPanel.moc
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o TabBarPanel.o src/TabBarPanel.cpp

ToolBoxView.o: src/ToolBoxView.cpp src/ToolBoxView.h \
		src/ToolBoxView.moc
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ToolBoxView.o src/ToolBoxView.cpp

Utility.o: src/Utility.cpp src/Utility.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Utility.o src/Utility.cpp

moc_BlackBoardApp.o: moc_BlackBoardApp.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_BlackBoardApp.o moc_BlackBoardApp.cpp

moc_BlackBoardPanel.o: moc_BlackBoardPanel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_BlackBoardPanel.o moc_BlackBoardPanel.cpp

moc_BlackBoardPanelScene.o: moc_BlackBoardPanelScene.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_BlackBoardPanelScene.o moc_BlackBoardPanelScene.cpp

moc_Board.o: moc_Board.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_Board.o moc_Board.cpp

moc_BoardPanel.o: moc_BoardPanel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_BoardPanel.o moc_BoardPanel.cpp

moc_BoardScene.o: moc_BoardScene.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_BoardScene.o moc_BoardScene.cpp

moc_BoardStrip.o: moc_BoardStrip.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_BoardStrip.o moc_BoardStrip.cpp

moc_BoardView.o: moc_BoardView.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_BoardView.o moc_BoardView.cpp

moc_CmdWindow.o: moc_CmdWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_CmdWindow.o moc_CmdWindow.cpp

moc_ContentPanel.o: moc_ContentPanel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ContentPanel.o moc_ContentPanel.cpp

moc_HierarchyView.o: moc_HierarchyView.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_HierarchyView.o moc_HierarchyView.cpp

moc_MainPanel.o: moc_MainPanel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_MainPanel.o moc_MainPanel.cpp

moc_ObjectPanel.o: moc_ObjectPanel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ObjectPanel.o moc_ObjectPanel.cpp

moc_PropertyView.o: moc_PropertyView.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_PropertyView.o moc_PropertyView.cpp

moc_TabBarPanel.o: moc_TabBarPanel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_TabBarPanel.o moc_TabBarPanel.cpp

moc_ToolBoxView.o: moc_ToolBoxView.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ToolBoxView.o moc_ToolBoxView.cpp

qrc_BlackBoard.o: qrc_BlackBoard.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_BlackBoard.o qrc_BlackBoard.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:
