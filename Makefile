trash := main.aux main.log main.out main.pdf


main.pdf: main.aux
	xelatex main

main.aux: main.tex $(wildcard *.tex)
	xelatex main

clean:
	$(RM) $(trash)

.PHONY: clean cleanall
