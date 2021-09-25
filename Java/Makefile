JC = javac
JCOPT = -g

src_dir = plusOne
src = $(wildcard $(src_dir)/*.java)

args =
.class = $(src:.java=.class)

all: run

run: $(.class)
	java $(src_dir).Main $(args)

$(.class): $(src)
	$(JC) $(JCOPT) $(src)

clean:
	$(RM) $(.class)
