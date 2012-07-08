CXXFLAGS=-std=c++0x -g -I ../kiwi -I .

CONTROLLERS=posts
MODELS=post

SRCS=main.cc config/routes.cc $(patsubst %, app/controllers/%.cc, $(CONTROLLERS)) $(patsubst %, app/models/%.cc, $(MODELS))
OBJS=$(patsubst %.cc, %.o, $(SRCS))

all: blog

blog: $(OBJS) ../kiwi/bin/libkiwi.a
	g++ -o blog $(OBJS) -L../kiwi/bin -lkiwi -lboost_regex

%.d: $(SRCS)
	$(CC) $(CXXFLAGS) -MM -MG -MT $*.o $*.cc > $@

include $(SRCS:.cc=.d)

%.cc: %.ecc
	../kiwi/bin/ecc `echo "$@" | sed -e 's/app\/views\/\(.*\)\/\(.*\)\.cc/config::ApplicationController::view_\1_\2/'` "#include <config/controller.h>" < $< > $@
