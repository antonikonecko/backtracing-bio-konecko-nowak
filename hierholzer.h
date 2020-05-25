#ifndef __HIERHOLZER_H__
#define __HIERHOLZER_H__


void euler(struct graph *g, int *cycle)
{
    struct stack *s = stack_create(g->size * g->size);  
    int u = 0;                                             
    stack_push(s, u);                                   

    while(!stack_is_empty(s))                           
    {
        u = stack_peek(s);
        int v = 0;                              
        while (v < g->size)                                
        {
            for(v = 0; v < g->size; v++)                   
            {
                if(graph_has_edge(g, u, v))                
                {
                    graph_remove_edge(g, u, v);           
                    stack_push(s, v);                   
                    u = v;                                 
                    v = 0;                                 
                    break;                                
                }
            }
        }
    *cycle = stack_pop(s);                              
    cycle++;                                               
    }
}
#endif
