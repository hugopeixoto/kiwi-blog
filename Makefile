CXXFLAGS=-std=c++0x -g -I ../kiwi -I .

CONTROLLERS=posts

VIEWS=app/views/posts/index.cc
SRCS=main.cc config/routes.cc $(patsubst %, app/controllers/%.cc, $(CONTROLLERS))
OBJS=$(patsubst %.cc, %.o, $(SRCS))

all: blog

blog: $(OBJS) $(VIEWS) ../kiwi/bin/libkiwi.a
	g++ -o blog $(OBJS) -L../kiwi/bin -lkiwi -lboost_regex

%.d: $(SRCS)
	$(CC) $(CXXFLAGS) -MM -MG -MT $*.o $*.cc > $@

include $(SRCS:.cc=.d)

%.cc: %.ecc
	../kiwi/bin/ecc `echo "$@" | sed -e 's/app\/views\/\(.*\)\/\(.*\)\.cc/\1 \2/'` < $< > $@
