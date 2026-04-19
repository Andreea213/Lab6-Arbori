int inaltime (struct node* nod)
{
    if (nod==NULL) return 0;
    int h_st=inaltime(nod->leftChild);
    int h_dr=inaltime(nod->rightChild);
    if (h_st>h_dr) return 1+h_st;
    return 1+h_dr;
}

bool echilibrat(struct node* nod)
{
    if (nod==NULL) return true;
    int l = inaltime(nod->leftChild);
    int r = inaltime(nod->rightChild);
   
    if (abs(l - r) <= 1 && echilibrat(nod->leftChild) && echilibrat(nod->rightChild))  return true;
    
    return false;
}    
