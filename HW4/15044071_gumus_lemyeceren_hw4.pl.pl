% -> Lemye Ceren Gümüs
% -> 151044071



flight(edirne,edremit).

flight(edremit,edirne).
flight(edremit,erzincan).

flight(erzincan,edremit).

flight(istanbul,izmir).

flight(izmir,istanbul).
flight(izmir,isparta).

flight(isparta,izmir).
flight(isparta,burdur).

flight(burdur,isparta).

flight(istanbul,antalya).

flight(antalya,istanbul).
flight(antalya,konya).
flight(antalya,gaziantep).

flight(konya,antalya).
flight(konya,ankara).

flight(istanbul,gaziantep).

flight(gaziantep,istanbul).
flight(gaziantep,antalya).

flight(istanbul,ankara).

flight(ankara,istanbul).
flight(ankara,konya).
flight(ankara,van).

flight(istanbul,van).

flight(van,rize).
flight(van,ankara).

flight(istanbul,rize).

flight(rize,istanbul).
flight(rize,van).


%rules
route(X,Y) :- flight(X,Y).

%PART2

distance(istanbul, antalya, 483).
distance(edirne,edremit,912).

distance(edremit,edirne,912).
distance(edremit,erzincan,736).

distance(erzincan,edremit,736).

distance(istanbul,izmir,329).

distance(izmir,istanbul,329).
distance(izmir,isparta,309).

distance(isparta,izmir,309).
distance(isparta,burdur,25).

distance(burdur,isparta,25).

distance(antalya,istanbul,483).
distance(antalya,konya,192).
distance(antalya,gaziantep,592).

distance(konya,antalya,592).
distance(konya,ankara,227).

distance(istanbul,gaziantep,847).

distance(gaziantep,istanbul,847).
distance(gaziantep,antalya,592).

distance(istanbul,ankara,352).

distance(ankara,istanbul,352).
distance(ankara,konya,227).
distance(ankara,van,920).

distance(istanbul,van,1262).

distance(van,rize,373).
distance(van,ankara,920).

distance(istanbul,rize,968).

distance(rize,istanbul,968).
distance(rize,van,373).

%rules
sroute(X,Y,C) :- distance(X,Y,C).

%PART-3

enrol(a,102).
enrol(a,108).
enrol(b,102).
enrol(c,108).
enrol(d,341).
enrol(e,455).

when(102,10).
when(108,12).
when(341,14).
when(455,16).
when(452,17).


where(102,z23).
where(108,z11).
where(341,z06).
where(455,207).
where(452,207).

schedule(S,P,T) :- enrol(S,S1),when(S1,T),where(S1,P).

usage(P,T) :- where(S1,P),when(S1,T).

conflict(X,Y) :- when(X,T1),where(X,P1),when(Y,T2),where(Y,P2),P1 =:= P2,not(X ==Y),R is T1-T2,-2 < R,R < 2.

meet(X,Y) :- not(X ==Y),enrol(X,S1),enrol(Y,S2),when(S1,T1),when(S2,T2),where(S1,P1),where(S2,P2),T1 =:= T2,P1 =:= P2,!.
% PART-4

% ELEMENT (PART-4.1)
element(E, [E|_]).
element(E, [_|S]) :- element(E, S).

% UNION (PART-4.2)
helperUnion([],R,R). % Base case
helperUnion([X|S1],S2,S3) :- member(X,S2),helperUnion(S1,S2,S3),!. % İlk listenin ilk elemanı diğer listede varsa diğer elemana geçme
helperUnion([X|S1],S2,[X|S3]) :- not(member(X,S2)),helperUnion(S1,S2,S3). % İlk listenin ilk elemanı diğer listede yoksa sonuç listesine ekleme
union(S1,S2,S3) :- helperUnion(S1,S2,S3).


% INTERSECTION (PART-4.3)
helperIntersect([],_,[]). % Base case
helperIntersect([X|S1],S2,[X|S3]) :- member(X,S2),helperIntersect(S1,S2,S3),!. % Listedeki ilk eleman diğer listede varsa sonuç listesine ekleme
helperIntersect([_|S1],S2,S3) :- helperIntersect(S1,S2,S3). % Eğer ilk listedeki eleman diğer listede yoksa diğer elemana geçme
intersect(S1,S2,S3) :- helperIntersect(S1,S2,S3).


% EQUIVALENT (PART-4.4)

isSubset([],_).
isSubset([H|T],S2):-
    member(H,S2),
    select(H,S2,Z),
    isSubset(T,Z).
equivalent(S1,S2):-
    isSubset(S1,S2),
    isSubset(S2,S1).

