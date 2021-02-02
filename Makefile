TEXS=$(wildcard *.tex)
PDFS=$(patsubst %.tex,%.pdf,$(TEXS))

.PHONY: clean cleanall

clean:
	$(RM) `cat ../.gitignore` 

cleanall: clean
	$(RM) $(PDFS)

$(PDFS): $(TEXS)
	pdflatex $(patsubst %.pdf,%.tex,$@) && \
	pdflatex $(patsubst %.pdf,%.tex,$@) 
