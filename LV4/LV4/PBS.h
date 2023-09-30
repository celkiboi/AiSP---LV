#ifndef PBS_H
#define PBS_H

typedef struct pbs
{
	char c;
	struct pbs* lijevi;
	struct pbs* desni;
}PBS;

PBS* umetni_cvor(char c, PBS* glavni_cvor);

PBS* pretrazi_pbs(char trazeno, PBS* glavni_cvor);

PBS* novi_cvor(char c, PBS* lijevi, PBS* desni);

void ispisi_preorder(PBS* glavni_cvor);

void ispisi_inorder(PBS* glavni_cvor);

void ispisi_postorder(PBS* glavni_cvor);

void oslobodi_PBS(PBS* glavni_cvor);

#endif