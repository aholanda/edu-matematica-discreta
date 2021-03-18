PY_PACKS := jupyter networkx sympy

%.tex: %.ipynb
	jupyter nbconvert --to latex --no-input $<
trash += *.tex *_files

%.pdf: %.tex
	@xelatex $<
	@xelatex $<
trash += *.pdf

setup:
	@pip install $(PY_PACKS)
	@jupyter-nbextension install rise --py --sys-prefix
	@jupyter nbextension enable rise --py --sys-prefix

clean:
	$(RM) -r *.aux *.log *.out $(trash)
