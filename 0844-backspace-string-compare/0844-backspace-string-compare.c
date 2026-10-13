bool backspaceCompare(char* s, char* t) {
    char stack1[201];
    char stack2[201];
    int top1=-1, top2=-1;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='#'){
            if(top1>=0){
                top1--;
            }            
        }
        else{
            stack1[++top1]=s[i];
        }
    }
    for(int i=0;t[i]!='\0';i++){
        if(t[i]=='#'){
            if(top2>=0){
                top2--;
            }
        }
        else{
            stack2[++top2]=t[i];
        }
    }
    while(top1>=0&&top2>=0){
        if(stack1[top1]!=stack2[top2]){
            return false;
        }
        top1--;
        top2--;
    }
    return top1==top2;
}