class Solution {
public:
    int numSquares(int n) {
        queue< pair<int,int> > q;
        q.push(make_pair(n,0));
        
        vector<bool> visited(n+1, false);
        visited[n] = true;
        
        while(!q.empty()) {
        	int val = q.front().first;
        	int step = q.front().second;
            q.pop();
        	
        	if (val == 0) return step;
            for (int i=1; ; i++) {
                int a = val - i*i;
                if (a<0) break;
                if (a == 0) return step+1;
            	if (!visited[a]) {
            		q.push(make_pair(a, step+1));
            		visited[a] = true;
				}
            }
		}
        return n;
    }
};
