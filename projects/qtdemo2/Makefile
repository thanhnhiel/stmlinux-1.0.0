# Makefile for an A2F-Linux project

# This project's name
SAMPLE		:= qtdemo2

# Custom applcations subdirectories that this project
# needs to build. Edit this list as appropriate for your application.
CUSTOM_APPS	:= app app2/Makefile

# Include Make rules applicable to all projects
include ../Rules.make

app2/Makefile:
	if [ ! -e app2 ]; then \
		ln -s ${INSTALL_ROOT}/A2F/qt-4.7.3/demos/qt-demo ./app2; \
	fi
	cd app2 && ${INSTALL_ROOT}/A2F/qt-4.7.3/bin/qmake
	cd app2 && make