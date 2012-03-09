bin_PROGRAMS = samtools bcftools razip bgzip 

lib_LIBRARIES = libbam.a

BGZF_SOURCES = \
			   bgzf.c bgzf.h 

RAZF_SOURCES = \
			   razf.c razf.h 
				  
KNETFILE_SOURCES = \
				   knetfile.c knetfile.h 

LIBRARY_SOURCES = \
				  ${BGZF_SOURCES} \
				  ${KNETFILE_SOURCES} \
				  ${RAZF_SOURCES} \
				  kstring.c kstring.h \
				  bam_aux.c \
				  bam.c bam.h \
				  bam_import.c \
				  sam.c sam.h \
				  bam_index.c \
				  bam_pileup.c \
				  bam_lpileup.c \
				  bam_md.c \
				  faidx.c faidx.h \
				  bedidx.c \
				  bam_sort.c \
				  sam_header.c sam_header.h \
				  bam_reheader.c \
				  kprobaln.c kprobaln.h \
				  bam_cat.c 

BCFTOOLS_SOURCES = \
				   bcftools_src/bcf.c bcftools_src/bcf.h \
				   bcftools_src/bcf2qcall.c \
				   bcftools_src/bcfutils.c \
				   bcftools_src/call1.c \
				   bcftools_src/em.c \
				   bcftools_src/fet.c \
				   bcftools_src/index.c \
				   bcftools_src/kfunc.c \
				   bcftools_src/kmin.c \
				   bcftools_src/kmin.h \
				   bcftools_src/mut.c \
				   bcftools_src/prob1.c \
				   bcftools_src/prob1.h \
				   bcftools_src/vcf.c

samtools_SOURCES = \
				   ${LIBRARY_SOURCES} \
				   ${BCFTOOLS_SOURCES} \
				   bam2bcf.c bam2bcf.h \
				   bam2bcf_indel.c bam2depth.c \
				   bam_color.c bam_endian.h \
				   bam_mate.c \
				   bam_plcmd.c bam_qa.c \
				   bam_rmdup.c bam_rmdupse.c \
				   bam_stat.c bam_tview.c bamtk.c \
				   cut_target.c errmod.c errmod.h \
				   kaln.c kaln.h \
				   khash.h \
				   klist.h \
				   kseq.h \
				   ksort.h \
				   padding.c phase.c radix.h \
				   sam_view.c sample.c sample.h

samtools_LDADD = 

bcftools_SOURCES = \
				   ${LIBRARY_SOURCES} \
				   ${BCFTOOLS_SOURCES} \
				   bcftools_src/main.c

bcftools_LDADD =

razip_SOURCES = \
				${KNETFILE_SOURCES} \
				${RAZF_SOURCES} \
				razip.c

razip_LDADD =

bgzip_SOURCES = \
				${KNETFILE_SOURCES} \
				${BGZF_SOURCES} \
				bgzip.c

bgzip_LDADD =

libbam_a_SOURCES = \
				   ${LIBRARY_SOURCES}


EXTRA_DIST = LICENSE \
			 autogen.sh \
			 samtools.git.rev \
			 samtools.1

SUBDIRS = . 

docdir = ${datadir}/doc/${PACKAGE}

dist_doc_DATA = LICENSE samtools.1

ACLOCAL_AMFLAGS = -I m4
