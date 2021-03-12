def to_rna(dna_strand):
    nuc = {'G':'C','C':'G','T':'A','A':'U'}
    return ''.join(nuc[char] for char in dna_strand)
