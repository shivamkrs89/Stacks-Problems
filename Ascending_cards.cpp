You are given a list of integers cards, and are looking to order the cards in a way so that they are revealed in ascending order.

The cards are revealed in this manner: the top card is removed and revealed and then next card is moved to the back. This is repeated until there's no more cards.

Return an ordering of the cards such that they are revealed in ascending order.

Constraints

n ≤ 100,000 where n is the length of cards
Example 1
Input
cards = [1, 2, 3, 4, 5]
Output
[1, 5, 2, 4, 3]
Explanation
1 is removed and 5 is moved to the back, resulting in [2, 4, 3, 5].
2 is removed and 4 is moved to the back, resulting in [3, 5, 4]
3 is removed and 5 is moved to the back, resulting in [4, 5]
4 is removed and 5 is moved to the back, resulting in [5]
5 is removed and there's no more cards.
  
  //code
  vector<int> solve(vector<int>& cards) {
    int n=cards.size();
    if(n==0)
    return cards;
   sort(cards.begin(),cards.end());
   
   vector<int> vrev;
   deque <int> gq;

   gq.push_back(cards[n-1]);
   int i=n-2;
   while(i>=0)  //to reveal cards in ascending order we start from putting biggest card to deque and pop back card every time and bring back card to front and push current card to front respectively
   {
     int xb= gq.back();
     gq.pop_back();
     gq.push_front(xb); 
     gq.push_front(cards[i]);
     i--;
   }


   for(auto x:gq)
   {
       vrev.push_back(x);
   }

   return vrev;
}
