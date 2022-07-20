#include "CTDL_DSMB.h"
using namespace std;
struct nodetype{
	int cmnd;
	string ho;
	string ten;
	int phai;
	int bf;
	nodetype *left;
	nodetype *right;
	
};
typedef nodetype* KHACHHANG;
//Tìm giá tr? l?n nh?t c?a hai s?
int find_max(int a, int b) {
  return (a > b) ? a : b;
}

//Tìm chi?u cao c?a cây
int height(struct nodetype *Nod) {
  if (Nod == NULL)
    return 0;
  return Nod->bf;
}

// T?o nút
struct nodetype *create_node(int cm,string h, string t, int p) {
  struct nodetype *new_node = new nodetype;
    malloc(sizeof(struct nodetype));
  new_node->cmnd = cm;
  new_node->ho = h;
  new_node->ten = t;
  new_node->phai = p;
  new_node->left = NULL;
  new_node->right = NULL;
  new_node->bf = 1;
  return new_node;
}

// Xoay ph?i
struct nodetype *rotate_right(struct nodetype *y) {
  struct nodetype *x = y->left;
  struct nodetype *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->bf = find_max(height(y->left), height(y->right)) + 1;
  x->bf = find_max(height(x->left), height(x->right)) + 1;
  return x;
}

// Xoay trái
struct nodetype *rotate_left(struct nodetype *x) {
  struct nodetype *y = x->right;
  struct nodetype *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->bf = find_max(height(x->left), height(x->right)) + 1;
  y->bf = find_max(height(y->left), height(y->right)) + 1;
  return y;
}

// l?y h? s? cân b?ng
int get_balanceFactor(struct nodetype *Nod) {
  if (Nod == NULL)
    return 0;
  return height(Nod->left) - height(Nod->right);
}

// Chèn nút
struct nodetype *add_node(struct nodetype *node, struct nodetype *data) {
  // Tìm v? trí thích h?p d? thêm nút
  if (node == NULL)
    return (create_node(data->cmnd,data->ho,data->ten,data->phai));
  if (data->cmnd < node->cmnd)
    node->left = add_node(node->left, data);
  else if (data->cmnd > node->cmnd)
    node->right = add_node(node->right, data);
  else
    return node;
  // C?p nh?t h? s? cân b?ng và cân b?ng cây
  node->bf = 1 + find_max(height(node->left),
               height(node->right));
  int balance = get_balanceFactor(node);
  if (balance > 1 && data->cmnd < node->left->cmnd)
    return rotate_right(node);
  if (balance < -1 && data->cmnd > node->right->cmnd)
    return rotate_left(node);
  if (balance > 1 && data->cmnd > node->left->cmnd) {
    node->left = rotate_left(node->left);
    return rotate_right(node);
  }
  if (balance < -1 && data->cmnd < node->right->cmnd) {
    node->right = rotate_right(node->right);
    return rotate_left(node);
  }
  return node;
}

struct nodetype *find_minValue(struct nodetype *node) {
  struct nodetype *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}

// Xóa nút
struct nodetype *deleteNode(struct nodetype *root, int data) {
  // Tìm nút c?n xóa
  if (root == NULL)
    return root;
  if (data < root->cmnd)
    root->left = deleteNode(root->left, data);
  else if (data > root->cmnd)
    root->right = deleteNode(root->right, data);
  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      struct nodetype *temp = root->left ? root->left : root->right;
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      struct nodetype *temp = find_minValue(root->right);
      root->cmnd = temp->cmnd;
      root->right = deleteNode(root->right, temp->cmnd);
    }
  }

  if (root == NULL)
    return root;
  // C?p nh?t h? s? cân b?ng
  root->bf = 1 + find_max(height(root->left),
               height(root->right));
  int balance = get_balanceFactor(root);
  if (balance > 1 && get_balanceFactor(root->left) >= 0)
    return rotate_right(root);

  if (balance > 1 && get_balanceFactor(root->left) < 0) {
    root->left = rotate_left(root->left);
    return rotate_right(root);
  }

  if (balance < -1 && get_balanceFactor(root->right) <= 0)
    return rotate_left(root);

  if (balance < -1 && get_balanceFactor(root->right) > 0) {
    root->right = rotate_right(root->right);
    return rotate_left(root);
  }
  return root;
}

// In ra cây
void preorder_print(struct nodetype *root) {
  if (root != NULL) {
   cout<<root->cmnd<<": "<<root->ho<<" "<<root->ten<<" - "<<root->phai<<endl;
    preorder_print(root->left);
    preorder_print(root->right);
  }
}
void NLR(KHACHHANG root)
{
	if(root!=NULL)
	{
		cout<<root->cmnd<<endl;
		NLR(root->left);
		NLR(root->right);
	}
}
KHACHHANG NewKH(int cm, string h, string t, int f)
{
	KHACHHANG q= new nodetype;
	q->bf=1;
	q->left=NULL;
	q->right=NULL;
	q->cmnd=cm;
	q->ho=h;
	q->ten=t;
	q->phai=f;
	return q;
}
void num(KHACHHANG root,int &k)
{
	if(root!=NULL)
	{
		k++;
		num(root->left,k);
		num(root->right,k);
	}
}

struct nodetype *Edit_KH(KHACHHANG root, int cm,string h, string t, int ph)
{
	KHACHHANG p;
	p=root;
	while(p!=NULL && cm !=p->cmnd)
	{
		if(cm<p->cmnd) p=p->left;
		else p=p->right;
	}
	p->ho=h; p->ten=t; p->phai=ph;
	return root;
}
void ghi(KHACHHANG root,fstream &f)
	{
		if(root!=NULL)
		{
		f<<root->cmnd<<endl;
		f<<root->ho<<endl;
		f<<root->ten<<endl;
		f<<root->phai<<endl;
		ghi(root->left,f);
		ghi(root->right,f);
		}
	}

void  Ghifile_KH(KHACHHANG x)
{
	fstream f; 
	f.open("DSKH.txt", ios::out);
	
	int sl=0;
	num(x,sl);
	f<<sl<<endl;
	ghi(x,f);
	f.close(); // (4)	
}
void Docfile_KH(KHACHHANG &x)
{
	ifstream f;
	f.open("DSKH.txt");
	int sl;
	f>>sl;
	for(int i=0;i<sl;i++)
	{
		nodetype *p= new nodetype();
		f>>p->cmnd;
		f >> ws;
		getline(f, p->ho);
		f>>p->ten;
		f>>p->phai;
		x=add_node(x,p);
	}
	f.close();
}

//int main() {
//   KHACHHANG root = NULL;
//  	root = add_node(root, NewKH(14,"NGUYEN","A",1));
// 	 root = add_node(root, create_node(4,"NGUYEN","B",1));
// 	 root = add_node(root, create_node(144,"NGUYEN","C",1));
// 	 root = add_node(root, create_node(154,"NGUYEN","D",1));
// 	 root = add_node(root, create_node(1,"NGUYEN","E",1));
//  	NLR(root);
//  root = deleteNode(root, 144);
//  printf("\nSau khi xoa nut\n");
//  NLR(root);
//  root=Edit_KH(root,14,"nguyen","tin",1);
//  printf("\nSau khi sua sua\n");
//  NLR(root);
//  return 0;
//}
