    for(int i=1;i<=10;i++)
    {
        int xx = q[i].front();
        q[i].pop();
        int sum=t[i].w+t[i].r;
        if(cnt<xx)
        {
            cnt+=v[i].fi;
            q[i].push(max(cnt,xx));
            cnt+=v[i].se;
        }else if(cnt==xx)
        {
            int temp = cnt + t[i].w;
            temp += v[i].fi;
            q[i].push(max(temp,cnt+sum));
            cnt = temp + v[i].se;
        }
        else
        {
            
            if((cnt-xx)%(sum)==0)
            {
                int temp = cnt + t[i].w;
                temp += v[i].fi;
                q[i].push(max(temp,cnt+sum));   
                cnt=temp+v[i].se; 

            }else if((cnt-xx)%(sum)>t[i].w)
            {

                int temp=cnt+v[i].fi;

                q[i].push(max(temp,cnt+sum-((cnt-xx)%(sum))));
                cnt=temp+v[i].se;  
            }else
            {
                int temp=cnt+(t[i].w-(cnt-xx)%(sum));
                temp+=v[i].fi;
                q[i].push(max(cnt+sum-((cnt-xx)%(sum)),temp));
                cnt=temp+v[i].se;
            }
        }
        
        cout << cnt << endl;
    }  