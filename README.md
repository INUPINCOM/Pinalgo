# PINCOM-Algorithm Study

인천대학교 중앙동아리 PINCOM에서 진행하는 알고리즘 스터디입니다.  
프로그래머스 문제를 풀고, GitHub **Pull Request(PR)** 로 코드를 공유하며 서로 **리뷰(코멘트)** 합니다.

> 저장소: [INUPINCOM/Pinalgo](https://github.com/INUPINCOM/Pinalgo) · Organization: [INUPINCOM](https://github.com/INUPINCOM)

---

## 스터디 개요

| 항목 | 내용 |
|------|------|
| 인원 | 약 12명 |
| 일정 | **매주 화요일 19시** |
| 플랫폼 | [프로그래머스](https://school.programmers.co.kr/) |
| 언어 | **자유** (Python, Java, C++ 등) |
| 과제 공지 | **카카오톡 공지** 및 **디스코드** |

---

## 주차별 주제 (커리큘럼)

매주 **주제에 맞는 공통 문제 1문제**와 **개별 문제 1문제**를 풀이합니다.

1. 그리디  
2. DFS, BFS  
3. 정렬  
4. 이진 탐색  
5. 동적 계획법  
6. 최단 경로  
7. 그래프 이론  

실제 진행 주차·문제 링크는 **카카오톡·디스코드 공지**를 기준으로 합니다.

---

## 참여 방법

### 1) 저장소 받기 (clone)

```bash
git clone https://github.com/INUPINCOM/Pinalgo.git
cd Pinalgo
```

### 2) 최신 코드 받기

```bash
git checkout main
git pull origin main
```

### 3) 작업용 브랜치 만들기

**브랜치 이름 규칙**

```text
week-{주차번호}/{본인식별자}
```

- `{본인식별자}`: GitHub 아이디 또는 영문 이름  
- 예: `week-03/honggildong`, `week-03/jiyoon`

```bash
git checkout -b week-03/honggildong
```

### 4) 풀이 파일 추가

**폴더 규칙** — 아래 주차·주제 폴더 중 해당 주에 맞는 곳에만 파일을 둡니다.

```text
week-01-greedy/
week-02-dfs-bfs/
week-03-sort/
week-04-binary-search/
week-05-dp/
week-06-shortest-path/
week-07-graph/
```

해당 폴더 안에는 **본인 풀이 파일만** 추가합니다.

**파일 이름 규칙**

```text
{본인식별자}_{문제이름또는약어}.{확장자}
```

- 파일명은 **영문**으로 작성합니다.

예:

- `honggildong_target-number.py`
- `jiyoon_two-sum.java`

### 5) 커밋 후 원격에 올리기

```bash
git add .
git commit -m "week-03: add solutions"
git push -u origin week-03/honggildong
```

### 6) Pull Request(PR) 열기

1. GitHub 저장소 페이지에서 **Compare & pull request** 를 누릅니다.  
2. base는 **`main`**, compare는 **본인 브랜치**인지 확인합니다.  
3. 아래 **PR 본문 템플릿**을 채웁니다.  
4. 팀원이 코드에 **코멘트**를 남깁니다.

---

## PR 본문 템플릿

PR을 열 때 아래 형식을 **그대로 쓰고**, 빈칸을 채웁니다.

```markdown
## 문제
- 공통: (프로그래머스 링크)
- 개별: (프로그래머스 링크)

## 메모
- 시간 복잡도 / 공간 복잡도:
- 리뷰에서 확인받고 싶은 점:
```

---

## Merge

- **Merge**는 PR에 올린 변경을 **`main` 브랜치에 합치는 작업**입니다.  
- Merge가 끝나면 스터디원 모두가 `git pull`로 동일한 기준을 맞출 수 있습니다.  
- **리뷰를 확인한 뒤, PR을 연 사람이 `main`에 Merge합니다.**  
  저장소 설정 때문에 본인에게 Merge 권한이 없으면 **운영진에게 Merge를 요청**합니다.

---

## 운영 규칙 · 주의사항

- **문제 지문 전문**을 저장소에 그대로 올리지 않습니다. **프로그래머스 링크**로 대체합니다.  
- **타인 코드 무단 복사·그대로 제출**은 스터디 목적에 맞지 않습니다. (참고는 가능하나, 이해·출처를 전제로 합니다.)  
- 실행 환경은 **로컬 실행**이든 **프로그래머스 제출**이든 **자유**입니다. PR에는 **실제로 돌려 볼 수 있는 소스**를 올립니다.

---

## 연락

- **카카오톡·디스코드**는 동아리 **내부 공지**를 참고해 주세요.  
- 외부 공개 가능한 초대 링크가 필요하면 **운영진**에게 문의해 주세요.

---

## Organization

- [INUPINCOM on GitHub](https://github.com/INUPINCOM)
