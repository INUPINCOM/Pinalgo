def solution(N, stages):
    answer = []
    # 입출력 예에서 알고리즘을 귀납해 보면 1 스테이지 실패율 = 스테이지가 1인 사람/N->2 스테이지 실패율 = 스테이지가 2인 사람/(N - 스테이지가 1인 사람)->3stage 실패율 = stage가 3인 사람/(N-stage가 3보다 작은 사람).. 이다.
    #그니까 그냥 이차원 배열에 지지고 볶고 나누면 될 듯? 꼭 필요한 원소는 실패율과 스테이지만 있으면 되니까.. 나머지 변수들은 매개변수에 담아뒀다가 갈아 끼워야겠다.
    failure_rate = [[0, i + 1, N - i] for i in range(N)]
    #[[실패율, 스테이지, N - 스테이지], [실패율, 스테이지, N - 스테이지]..]
    
    stages.sort()

    present_stage = stages[0]
    present_player = len(stages)
    same_stage_num = 0
    
    for stage in stages:
        if stage != present_stage: #기존의 스테이지와 다르다면
            failure_rate[present_stage - 1][0] = same_stage_num/present_player # stage가 k인 사람/(N - stage가 k보다 작은 사람)
                
            # 업데이트
            present_stage = stage
            present_player -= same_stage_num
            same_stage_num = 0
        same_stage_num += 1
    
    if present_stage != N + 1: # 마지막까지 클리어한 사용자가 아니라면
        failure_rate[present_stage - 1][0] = same_stage_num/present_player # [4, 4, 4, 4, 4]같이 한 번도 안 바뀌는 상황 대비 + [1, 1, 2, 2] 처럼 마지막까지 깬 사람이 없을 때 2번 스테이지 실패율 업데이트 해줘야 함

    # 이제 정렬
    def x(item): return item[0], item[2] #일단 실패율로 정렬하고, 그거 같으면 스테이지 반대로 정렬하셈(리버스 할 거니까)
    failure_rate.sort(key = x, reverse = True)
    
    for item in failure_rate:
        answer.append(item[1])
    
    print(failure_rate)
    return answer