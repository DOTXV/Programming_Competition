/*
TLE in this case
[[43,46,199],[6,9,149,157],[27,192],[24,45,63,99,108,117],[38,53,92,109,159],[42],[155],[42,45,94,154,156,194],[32,116,132,170,185],[10],[25,72,95,187],[147,152,176],[24,172],[16,62,72,102,175,194],[5,179,198],[],[20,122,157,172],[39,54,120,128,162,163],[19,65,77,82,143,167],[70,118,147],[34,60,79,123],[34,55,105,191],[74,141],[49,155,189],[83,104,183],[57],[64,123,129],[55,155,174,182],[104,153],[51,124,133,166],[90,161],[70],[],[45,93,160],[41,62,80,199],[42,114],[48,58,67,76,185],[],[126,128,143,195,199],[73],[68,122,135],[172,184],[117,144,186,190],[104,106,141,180],[],[59,68,80,81,104],[124,166],[83,137,152,188],[75,155],[61,63,73,76,158,171],[12,93,96,139,166],[57,69,100,107,135],[54,102,115,141,146,153],[110,191,196,197],[149],[116,155],[89,128,163],[77,83,87,94,187],[123,136,142],[96,135,143,192],[66,80,105,120,151,166],[99,104],[67,106,135,165,199],[70,176],[81,92,172,183],[72,97,118,151,187],[157,165,179,180,196],[77,88,94,112],[],[92,127,144,162],[79,95,157,169,174,191],[108,135,198],[81,92,162,185,188],[132,134,148],[88,91,166,185,197],[],[134],[142],[94,108,114,146,156],[147,174],[130,148,164],[112],[95],[],[81,120],[99,110,131,134,165,193],[116,173,175],[114,129,161,172],[],[96,127,141,148,154],[140,143,159,166],[105,118,156,186],[128,159,195],[98],[111],[186],[99,104,130,133,149],[153],[120,148,161,175],[127,182],[],[135,138,154,158,198],[41],[103,121],[133,139,158,177,195],[193],[72,174],[108,120,125,127,163],[],[138,164],[132,139,141,144,164],[126],[89,119,140,175,191,193],[120,126,164,187],[89,139,158,163],[],[160],[153,155],[199],[126,135,153,156,195],[128,134,165,166],[128,170,193,195],[136,144,169],[125,149,152,155,180,192],[194],[134,136,140,181],[144,157,158,164,177],[136,185,196],[142,145,162,189],[151,154,158,172,195],[],[166,178,195],[145],[136,149,155,160,178,192],[135,137,174,176,186],[179,194],[],[],[145,152,154,158,164],[159,168,181,195,196],[150,174,175],[111,184,199],[160,164,197],[159,161,170,188],[145,168],[168,194],[191],[152,156],[],[153,169,183,193,199],[156,173],[],[173],[180,192],[165],[],[176,180,186,188,190,196],[183,186,187],[165,168,179,192,194],[166,190],[177,178],[188,196,197],[181],[97,172,178,185,187,190,193],[166,167,172,175,187],[176,177,181,182,192],[173],[42,171,176,188,192],[177,179,181,193,195,197],[170,178,181,183,191,197],[173,191],[176,184,188,189],[178,181,192,193,195],[185,199],[179,182,183,187,199],[177,182,190,197,198,199],[183,185,189,190,198],[178,185,189,191,195,198],[180,185,187],[181,182,187,199],[182],[185,190,194],[],[186,188,190,192,194,196],[190,191,197,199],[190],[188,190,192,198,199],[188,190,191,193,194,197],[198],[190,194],[195],[196,199],[194],[194,196,197,199],[],[196,197,198],[197,198,199],[198,199],[199],[]]
*/
#define FORI(n) for(int i = 0; i < n; ++ i)
class Solution
{
public:
    vector<int> res, visited;
    vector<int> traversed_path;
    int cycle_cnt;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        res.resize(graph.size());
        fill(res.begin(), res.end(), -1); //initialize all the result to be false
        FORI(graph.size())
        {
            if(graph[i].size()) //if this node is not the terminal node
            {
                //going to its next node
                visited.resize(graph.size());
                fill(visited.begin(), visited.end(), 0);
                cycle_cnt = 0;
                // printf("Start from:  %d \n",i);
                traversed_path.clear();
                dfs(i, i, graph, 0); //directly go to its next node, if the next node is still itself, a cycle formed
                if(cycle_cnt == 0)
                {
                    res[i] = 1;
                } //this node gives no circle, that traverse back to itself satisfie the requirements
                else
                {
                    res[i] = -1;
                }
            }
            else
            {
                res[i] = 1;//directly push back it since such node is a terminal
            }
        }
        vector<int> final_res;
        FORI(res.size())
        {
            if(res[i] == 1)
            {
                final_res.push_back(i);
            }
        }
        return final_res;
    }
    void dfs(int cur_node, int start, vector<vector<int>> graph,int step)
    {
        // printf("Now traversed use DFS to %d with curent step %d and traversed path: \n",cur_node,step);
        /*FORI(traversed_path.size())
        {
            cout<<traversed_path[i]<<" ";
        }*/
        if(find(traversed_path.begin(), traversed_path.end(), cur_node)!= traversed_path.end() && step && traversed_path.size()) //check whether the current node has been visited before, if so a cycle formed
        {
            // cout<<" Find a cycle!! in step "<<step<<endl;
            cycle_cnt = 1;
            return; //then we can end the function since a cycle has been detected, and theat is our mission
        }
        else
        {
            traversed_path.push_back(cur_node);
            visited[cur_node] = 1;
            FORI(graph[cur_node].size()) //search the next node that can be traversed from the current node
            {
                if(!visited[graph[cur_node][i]])
                {
                    dfs(graph[cur_node][i], start, graph, step + 1);
                }
                else if(visited[graph[cur_node][i]] && graph[cur_node][i] == start)//has been visited before(visit value = 1), but meet again-->cycle
                {
                    // cout<<" Find a cycle IN NEXT NODE!! in step "<<step<<endl;
                    cycle_cnt = 1;
                    return;
                }
                else if(visited[graph[cur_node][i]] && find(traversed_path.begin(), traversed_path.end(), graph[cur_node][i])!= traversed_path.end())//has been visited before(visit value = 1), but meet again-->cycle
                {
                    // cout<<" Find a cycle IN NEXT NODE!! in step "<<step<<endl;
                    cycle_cnt = 1;
                    return;
                }
                else if(visited[graph[cur_node][i]] && graph[cur_node][i] == cur_node) //self cycle
                {
                    // cout<<" Find a cycle SELF CYCLE !!! in step "<<step<<endl;
                    cycle_cnt = 1;
                    return;
                }
            }
        }
        /*FORI(traversed_path.size())
        {
            cout<<traversed_path[i]<<" ";
        }
        cout<<endl;*/
        visited[cur_node] = false; //reach end and back track to find the next
        cur_node = traversed_path.back();
        // cout<<"Back trace to "<<cur_node<<endl;
        traversed_path.pop_back();
    }
};
