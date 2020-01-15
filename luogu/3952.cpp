#include<iostream>
#include<sstream>
#include<stack>
#include<set>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		int L;
		string comp; //�����ʱ�临�Ӷ� 
		int ans=0; //ʵ�ʵĸ��Ӷ��ݴΣ���n^ans 
		int err=0; //�����־
		
		string str, i, x, y;
		stack<string> cs, is; //csѭ��Ƕ�ױ�־��is����ջ 
		stack<int> level; //ѭ���㼶
		set<string> has_i; //��ѯ�����Ƿ��Ѿ����� 
		
		cin>>L>>comp;
		level.push(0); //��ʼ�ݴ�Ϊ0 
		
		while(L--){
			cin>>str;
			if(str=="F"){
				cin>>i>>x>>y;
				if(!err && has_i.find(i)==has_i.end()){ //����������ͻ 
					cs.push("F"); is.push(i); has_i.insert(i); 
					if(x=="n" && y!="n"){ // n������
						level.push(-1);   //-1��ʾ��ѭ������Ч 
					} 
					else if(x!="n" && y=="n"){ // ���֡�n 
						if(level.top()!=-1){ //�����һ���ݴβ�Ϊ-1�����ݴ�+1 
							level.push(level.top()+1);
							ans=max(ans, level.top());
						}
						else level.push(-1); //�����һ���ݴ�Ϊ-1, ����һ����ݴ�ͬ��Ϊ-1 
					}
					else if(x!="n" && y!="n"){ //���֡����� 
						if(stoi(x)<=stoi(y)) level.push(level.top()); //x<=y �ݴβ��� 
						else level.push(-1); //x>y ��ѭ������Ч 
					}
					else{ // n��n 
						level.push(level.top());
					}
				}
				else err=1; //��������ͻ 
			}
			else if(!err && str=="E"){ //һ��ѭ������� 
				if(!cs.empty() && cs.top()=="F"){
					cs.pop(); has_i.erase(is.top()); is.pop(); //��һ��Ƕ�׽��������ٱ��� 
					level.pop(); //�ص���һ�� 
				}
				else err=1; //�﷨���� 
			}
		} 
		
		if(err || !cs.empty()) cout<<"ERR"<<endl;
		else if(ans==0 && comp=="O(1)" || ans>0 && comp=="O(n^"+to_string(ans)+")") cout<<"Yes"<<endl;
		else cout<<"No"<<endl; 
	}
	return 0;
}
