TSXS=/usr/local/ats620/bin/tsxs
TARGET=plugin_test.so
SRCS=file_log.c plugin_main.c
${TARGET}: ${SRCS}
	${TSXS} -o $@ -c $^
install:
	${TSXS} -o ${TARGET} -i
clean:
	rm -f *.lo ${TARGET} 
