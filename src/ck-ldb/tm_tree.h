#ifndef __TREE_H__
#define __TREE_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _tree_t{
  struct _tree_t **child;
  struct _tree_t *parent;
  struct _tree_t *tab_child; /*the pointer to be freed*/
  double val;
  int arity;
  int depth;
  int id;
  int uniq;
  int dumb; /* 1 if the node belongs to a dumb tree: hence has to be freed separately*/
}tree_t;

/* Maximum number of levels in the tree*/
#define MAX_LEVELS 100

typedef struct {
  int *arity; /* arity of the nodes of each level*/
  int nb_levels; /*number of levels of the tree*/ 
  int *nb_nodes; /*nb of nodes of each level*/
  int **node_id; /*ID of the nodes of the tree for each level*/
}tm_topology_t;



tree_t * build_tree(double **tab,int N);
tree_t * build_tree_from_topology(tm_topology_t *topology,double **tab,int N,double *obj_weight, double *comm_speed);
void map_tree(tree_t *,tree_t*);
void display_tab(double **tab,int N);
double speed(int depth);
void set_node(tree_t *node,tree_t ** child, int arity,tree_t *parent,int id,double val,tree_t *deb_tab_child);
void free_tree(tree_t *tree);
void free_tab_double(double**tab,int N);
void free_tab_int(int**tab,int N);
void update_val(double **tab,tree_t *parent,int N);

typedef struct _group_list_t{
  struct _group_list_t *next;
  tree_t **tab;
  double val;
  double sum_neighbour;
  double wg;
}group_list_t;


typedef struct{
  int i;
  int j;
  double val;
}adjacency_t;


#ifdef __cplusplus
}
#endif


#endif

