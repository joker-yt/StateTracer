SUBDIRS = src
TESTDIR = test
SAMPLEDIR = sample
DOCDIR = doc
TAGS = ctags

all:
	@for i in $(SUBDIRS) ; \
	do \
	$(MAKE) -C $$i $@; \
	done
	$(TAGS) -R

sample:
	@for i in $(SAMPLEDIR) ; \
	do \
	$(MAKE) -C $$i $@; \
	done

doc:
	@for i in $(DOCDIR) ; \
	do \
	$(MAKE) -C $$i $@; \
	done

clean:
	@for i in $(SUBDIRS) $(TESTDIR) $(SAMPLEDIR) $(DOCDIR) ; \
	do \
	$(MAKE) -C $$i $@; \
	done
