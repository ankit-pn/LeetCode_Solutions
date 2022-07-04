class Solution {
public:
   bool isValidSerialization(string s)
{
    // we can simple do it by stack.
    // if top is # and we incounter # again , then pop# and element that is on top afterpoping hash.
    // insert #.
    // periods.
    stack<string> st;
    int i = 0;
    int n = s.length();
       if(n==1 && s[0]=='#')
           return 1;
       else if(s[0]=='#')
           return 0;
    while (i < s.length())
    {
        if(st.size()==1 && st.top()=="#")
                break;
        if (s[i] == '#')
        {
            if (st.top() != "#")
            {
                st.push("#");
                 if(st.size()==1 && st.top()=="#")
                break;
            }
            else
            {
               
                while(!st.empty() && st.top()=="#"){
                     int c=0;
                while(st.top()=="#"){
                    st.pop();
                    c++;
                }
                while(c--){
                    st.pop();
                    if(c>0 && st.size()==0)
                    return 0;
                }
                }
                
                st.push("#");
            }
            i += 2;
            if(st.size()==1 && st.top()=="#")
                break;
            continue;
        }
        else
        {
            string to_push = "";
            to_push += s[i];
            i++;
            if (i < n && s[i] != ',')
            {
                to_push += s[i ];
                i++;
                if (i  < n && s[i] != ',')
                {
                    to_push += s[i];
                    i++;
                }
            }
            i++;
            st.push(to_push);
            // cout<<i+1<<"\n";
        }
    }
    return st.size()==1&&st.top()=="#"&&i==n+1;
}


};