import glob
import os

BUILD_DIR = "build"
OBJS_DIR = BUILD_DIR + "/obj"

SOURCES = glob.glob("source/*.c")
OBJS = [f.replace('source', OBJS_DIR).replace('.c', '.o') for f in SOURCES]
HEADERS = glob.glob("includes/*.h")
PROGRAM = BUILD_DIR + "/main.x"

env = Environment(CC = 'gcc', CCFLAGS = '-Wall -Wextra -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wcast-qual -Wswitch-default -Wswitch-enum  -Wconversion -Wunreachable-code -std=c11')

for i in range(len(SOURCES)):
    env.Object(target = OBJS[i], source = SOURCES[i])

env.Object(target=OBJS_DIR + '/main.o', source='main.c')
env.Program(target = PROGRAM, source = OBJS + [OBJS_DIR + '/main.o'])

Library('lib/nbody', OBJS)