# Linked List
## Single Linked List
* Design a Linked List class with some basic methods. You should be able to implement those with out too much efforts. 
## Two Pointer Technique
* Find Linked List cycle
> use fast pointer and slow pointer, if they can encounter , then it means that there is a cycle in the list. For implementation, be careful that if fast->next if null before move two steps further(e.g. fast = fast->next->next)
* Find the entry node of the cycle
> First you need to check if there exists a cycle. Then some mathematical analysis should be done , a awesome solution and explanation can be found in leetcode discussion board.
* Intersection of Two Linked Lists
> This problem is really tricky , regular solution or mathematical analysis is hard, but it would be pretty easy if you know the trick. The basic idea si simple, and can be found in discussion board.Actually, almost every published solution used this trick. 

## Classic Problems.
* Reverse Linked List
> This problem can be solved recursively or iteratively, I prefer iteration because I believe it is safer than recursion. The basic idea is that you can choose the original head node as the black node and then move its next node to the head iteratively until it reaches the end node.
* Remove Linked List Elements.
> This problem is easy, using two pointer tech can solve it without too much efforts, but you should be careful of the corner case.
* Odd Even Linked List.