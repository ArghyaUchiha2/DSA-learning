oid tree::iterativePostorder(Node *p)
// {
//     stack<long int> stk;
//     long int temp;
//     while (p!=NULL || !stk.empty())
//     {
//         if(p!=NULL)
//         {
//             stk.emplace((long int)p);
//             p=p->lchild;
//         }
//         else
//         {
//             temp=stk.top();
//             stk.pop();
//             if(temp>0)
//             {
//                 stk.emplace(-temp);
//                 p=((Node*)temp)->rchild;
//             }
//             else
//             {
//                 cout<<((Node*)(-1*temp))->data<<" ";
//                 p=NULL;
//             }
//         }
//     }
//     cout<<endl;
    
// }