import glob
import os

SOURCES = glob.glob("source/*.c")
OBJS = [f.replace('source', 'obj').replace('.c', '.o') for f in SOURCES]
HEADERS = glob.glob("includes/*.h")
PROGRAM = "main.x"

env = Environment(CC = 'gcc', CCFLAGS = '-Wall -Wextra -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wcast-qual -Wswitch-default -Wswitch-enum  -Wconversion -Wunreachable-code -std=c11')

for i in range(len(SOURCES)):
    env.Object(target = OBJS[i], source = SOURCES[i])

env.Program(target = PROGRAM, source = OBJS)