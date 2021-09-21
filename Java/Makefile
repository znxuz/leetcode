JC = javac
JCOPT = -g

src_dir = two_sum
src = $(wildcard $(src_dir)/*.java)

.class = $(src:.java=.class)

all: run

run: $(.class)
	java $(src_dir).Main

$(.class): $(src)
	$(JC) $(JCOPT) $(src)

clean:
	$(RM) $(.class)
