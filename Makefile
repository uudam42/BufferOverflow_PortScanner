all: vuln safe scanner

vuln: vuln.c
	gcc -g vuln.c -o vuln -fno-stack-protector -no-pie

safe: safe.c
	gcc -g safe.c  -o safe

scanner: scanner.c
	gcc -g scanner.c -o scanner

clean:
	rm -f vuln safe scanner

