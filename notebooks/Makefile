%.tex: %.ipynb
	jupyter nbconvert --to latex --no-input $<
trash += *.tex *_files

%.pdf: %.tex
	@xelatex $<
	@xelatex $<
trash += *.pdf

clean:
	$(RM) -r *.aux *.log *.out $(trash)