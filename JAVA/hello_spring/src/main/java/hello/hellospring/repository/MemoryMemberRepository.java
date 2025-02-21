package hello.hellospring.repository;

import hello.hellospring.domain.Member;

import java.util.*;

// 자바 interface를 이용해 implements. 이제 메서드 오버라이드 해야겠지?
public class MemoryMemberRepository implements MemberRepository {
    private static Map<Long, Member> store = new HashMap<>();
    private static long sequence = 0L;// 시퀀스 : 키값 자동 생성

    @Override
    public Member save(Member member) {
        member.setId(++sequence);
        store.put(member.getId(), member);  // set했던 ID는 hash의 key, member는 hash의 value로 한다
        return member;
    }

    @Override
    public Optional<Member> findById(String id) {
        
        return Optional.ofNullable(store.get(id));  // Null 발생시 Null 반환
    }

    @Override
    public Optional<Member> findByName(String name) {
        return store.values().stream()
                .filter(member-> member.getName().equals(name))
                .findAny(); // name과 같은 값을 member.getName으로 찾고 없을 시 (Optional임으로) Null 반환.

    }

    @Override
    public List<Member> findAll() {
        return new ArrayList<>(store.values()); // 모든 member값(ID, name 출력
    }
}
