#include<iostream>
using namespace std;
template<class T>
class pre
{
    T a[100];
    int maxsize,sp;
    public:
        pre(int m)
        {
            sp=-1;
            maxsize=m;
        }
        int isfull()
        {
            return (sp==maxsize-1);
        }
        int isempty()
        {
            return (sp==-1);
        }
        void push(T );
        T pop();
        int precedence(T);
        void convert();
    };
    template<class T>
    void pre<T>::push(T c)
    {
        if(!isfull())
        a[++sp]=c;
        else
        cout<<"stak owerflow:\n";
    }
    template<class T>
    T pre<T>::pop()
    {
        if(!isempty())
        {
            T c;
            c=a[sp--];
            return c;
        }
        cout<<"stak under flow:\n";
    }
    template<class T>
    int pre<T>::precedence(T ch)
    {
        switch(ch)
        {
            case '*':
            case '/':
            case '%': return 3;
            case '+':
            case '-': return 2;    
            case ')': return 1;
            case '#': return 0;
        }
    }
    template<class T>
    void pre<T>::convert()
    {
        push('#');
        T infix[100],prefix[100],ch,reverse[100];
        cout<<"enter the infix expression:\n";
        cin>>infix;
        int f=0,k=0;
        while(infix[f]!='\0')
        {
          k++;
          f++;
        }
        int g=0;
        for(f=k;f>0;f--)
        {
            reverse[g]=infix[f];
            g++;
            cout<<reverse;
        }
        for(int j=0;j<k;j++)
        {
        infix[j]=reverse[j];
        }
        int i=0,p=0;
        while(infix[i]!='\0')
        {
            ch=infix[i];
            if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9'))
            prefix[p]=ch;
            else
            if(ch==')')
            push(ch);
            else
            if(ch=='(')
            {
                while(a[sp]!=')')
                {
                    T c;
                    c=pop();
                    prefix[++p]=c;
                }
                pop();
            }
            else
            {
                int pre1=precedence(ch);
                int pre2=precedence(a[sp]);
                if(pre1>=pre2)
                push(ch);
                else
                {
                    T c;
                    c=pop();
                    push(ch);
                    prefix[++p]=c;
                }
            }
            i++;
        }
        int j=0;
        for(int s=k;s>=0;s--)
        {
        reverse[j]=prefix[s];
        j++;
        }
        for(int s=0;s<k;s++)
        {
            prefix[s]=reverse[s];
        }
        prefix[++p]='\0';
        cout<<"the prefix expression is:\n";
        for(i=0;i<k;i++)
        cout<<prefix[i];
        
    }
    int main()
    {
        pre<char>z(100);
        z.convert();
        int d;
        cin>>d;
    }
    
        
                   
        
