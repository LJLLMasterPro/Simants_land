# Makefile principal
# VARIABLES POUVANT ETRE REDEFINIS PAR L'UTILISATEUR
# DIRECTORY OU EST INSTALLE HPNUM :
PROJECT_ROOT = /home/juvigny/Cours.d/ParisVI/2017/simants_project
#/home/juvigny/Documents/Cours/Paris6/2018/simants_project
# /home/juvigny/Cours.d/ParisVI/2017/simants_project
# VOTRE COMPILATEUR PREFERE ( POUR PARIS 6, g++ suffira normalement )
CXX = g++
DEBUGOPT = -g -Wall -pedantic -fopenmp
OPTIMOPT = -O2 -march=native -fopenmp

CXXOPT = -std=c++11 -fPIC $(DEBUGOPT)

MPIROOT    = /usr/lib/openmpi

OPENGLINC      = /usr/include
OPENGLLIBROOT  = /usr/lib/x86_64-linux-gnu/

DOXYGENEXE = /usr/bin/doxygen
# FIN DES VARIABLES POUVANT ETRE REDEFINIES PAR L'UTLISATEUR

INCPATH= -I$(MPIROOT)/include                \
	     -I$(HPNUM_ROOT)/include

LIBPATH= -L$(OPENGLLIBROOT) -L$(HPNUM_ROOT)/lib 
