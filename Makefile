os = $(shell uname -s)

INCFLAGS      = -I$(ROOTSYS)/include -I$(FASTJETDIR)/include -I$(PYTHIA8DIR)/include -I$(PYTHIA8DIR)/include/Pythia8 -I/opt/local/include#-I$(STARPICODIR)
INCFLAGS      += -I${BASICAJDIR}/src

ifeq ($(os),Linux)
CXXFLAGS      = 
else
CXXFLAGS      = -O -fPIC -pipe -Wall -Wno-deprecated-writable-strings -Wno-unused-variable -Wno-unused-private-field -Wno-gnu-static-float-init
## for debugging:
# CXXFLAGS      = -g -O0 -fPIC -pipe -Wall -Wno-deprecated-writable-strings -Wno-unused-variable -Wno-unused-private-field -Wno-gnu-static-float-init
endif

ifeq ($(os),Linux)
LDFLAGS       = -g
LDFLAGSS      = -g --shared 
else
# LDFLAGS       = -O -Xlinker -bind_at_load -flat_namespace
# LDFLAGSS      = -flat_namespace -undefined suppress
# LDFLAGSSS     = -bundle
LDFLAGS       = 
endif

ifeq ($(os),Linux)
CXX          = g++ 
else
#CXX          = clang
CXX          = g++
endif


ROOTLIBS      = $(shell root-config --libs)

LIBPATH       = $(ROOTLIBS) -L$(FASTJETDIR)/lib -L$(PYTHIA8DIR)/lib #-L$(STARPICODIR)
#LIBS          = -lfastjet -lfastjettools -lpythia8 #-lTStarJetPico

LIBPATH       += -L$(BASICAJDIR)/lib
#LIBS	      += -lMyJetlib
LIBS           = 
LDFLAGS        = 
LIBPATH        = 

# for cleanup
SDIR          = src
ODIR          = src/obj
BDIR          = bin


###############################################################################
################### Remake when these headers are touched #####################
###############################################################################


###############################################################################
# standard rules
$(ODIR)/%.o : $(SDIR)/%.cxx $(INCS)
	@echo 
	@echo COMPILING
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $< -o $@

$(BDIR)/% : $(ODIR)/%.o 
	@echo 
	@echo LINKING
	$(CXX) $(LDFLAGS) $(LIBPATH) $(LIBS) $^ -o $@

###############################################################################

###############################################################################
############################# Main Targets ####################################
###############################################################################
all : $(BDIR)/matrix

#$(ODIR)/implement.o : $(SDIR)/implement.cxx $(SDIR)/vecNd.h
$(ODIR)/vecNd.o : $(SDIR)/vecNd.cxx $(SDIR)/vecNd.h
$(ODIR)/matrixNN.o : $(SDIR)/matrix.cxx $(SDIR)/matrixNN.cxx $(SDIR)/matrixNN.h $(ODIR)/vecNd.o

$(BDIR)/matrix : $(ODIR)/matrixNN.o $(ODIR)/vecNd.o#$(ODIR)/implement.o $(ODIR)/vecNd.o

###############################################################################
##################################### MISC ####################################
###############################################################################

clean :
	@echo 
	@echo CLEANING
	rm -vf $(ODIR)/*.o
	rm -vf $(BDIR)/*
	rm -vf lib/*


