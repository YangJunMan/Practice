package hello.hellospring.repository;

import hello.hellospring.domain.Member;
import java.util.*;

public interface MemberRepository {
    Member save(Member member); // 기능 save
    Optional<Member> findById(String id);   // id로 회원 찾기. 없으면 Null 자동 반환.
    Optional<Member> findByName(String name);   // name으로 회원 찾기.
    List<Member> findAll(); // 모든 회원 반환

}
