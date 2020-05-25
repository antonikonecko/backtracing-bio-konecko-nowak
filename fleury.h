#ifndef __FLEURY_H__
#define __FLEURY_H__

bool bridge(struct graph *g, int u, int v)
{
    struct graph *copy = graph_copy(g);                       
    int *visit1 = (int*) calloc(copy->size, sizeof(int));   
    int counter1 = 0;                                        
    dfs(copy, u, visit1);                                   
        for(int i = 0; i < copy->size; i++)                   
        {
            if(visit1[i] == 1)                               

    int *visit2 = (int*) calloc(copy->size, sizeof(int));   
    int counter2 = 0;
    graph_remove_edge(copy, u, v);
    dfs(copy, u, visit2);
    for(int j = 0; j < copy->size; j++)
        {
            if(visit2[j] == 1)
                counter2++;
        }

    if (counter1 == counter2 )                           
        return false;                                          
    else                                                       
        return true;                                          
}


int counting( struct graph *g, int u){
    int quantity = 0;
    for ( int i = 0; i < g->size ; i++){
        if(g->matrix[u][i] == 1)
            quantity++;
        }
    return quantity;
    }


void euler(struct graph *g, int *cycle) {
    struct graph *copy = graph_copy(g);                                 
    int u = 0;                                                         
    for (int i = 0; i < g->edges; i++)                                  
    {
        cycle[i] = u;                                               
        int amount = counting(copy, u);                                

        if(amount > 1)                                               
        {
            for(int v = 0; v < copy->size; v++)                    
            {
                if (graph_has_edge(copy, u, v) && !(bridge(copy, u, v))) 
                    {
                        graph_remove_edge(copy, u, v);                  
                        u = v;                                          
                        break;                                           
                    }
            }
        }
        else                                                             
            {
            for(int v = 0; v < copy->size; v++)                         
                {
                if (graph_has_edge(copy, u, v))                         
                        graph_remove_edge(copy, u, v);                  
                        u = v;                                           
                        break;                                           
                    }
                }
            }
    }
}

#endif
