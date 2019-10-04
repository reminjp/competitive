//
// HAL Programming Contest 2019 Viewer
// Copyright (c) 2019 HAL Laboratory, Inc.
//
'use strict';
const vm = new Vue({
  el: 'body',
  data: {
    json: false, stage: 0, turn: 0,
    playType: 0, isPlay: false, timer: null, isDrag: false,
    minColorTurn: 200, maxColorTurn: 500
  },
  computed: {
    stages: function () { return this.json; },
    stageWidth: function () { return this.stages[this.stage][1]; },
    stageHeight: function () { return this.stages[this.stage][2]; },
    turns: function () { return this.stages[this.stage][7]; },
    turtles: function () { return this.turns[this.turn]; },
    foods: function () { return this.stages[this.stage][6]; }
  },
  methods: {
    import: function (e) {
      const reader = new FileReader();
      reader.onload = (function () {
        return function (e) {
          try {
            vm.json = JSON.parse(e.target.result);
            vm.stage = 0;
          } catch (ee) {
            alert('JSONファイルが壊れています');
          }
        }
      })(e.target.files[0]);
      reader.readAsText(e.target.files[0]);
    },
    // ターンスライダーをドラッグしている際に呼ばれる関数
    drag: function (e) {
      const sliderRect = e.target.parentNode.getBoundingClientRect();
      this.turn = (e.clientX - sliderRect.left)*this.turns.length/sliderRect.width|0;
      this.isDrag = true;
    },
    // トータルターン
    totalTurn: function () {
      return this.stages.reduce(function (total, stage) { return total + stage[5]; }, 0).toLocaleString();
    },
    // ターン数に応じて、赤〜緑の色値を計算する関数
    stageColor: function (no) {
      var d = 1 - (this.stages[no][5] - this.minColorTurn)/(this.maxColorTurn - this.minColorTurn);
      d = Math.min(Math.max(d, 0), 1);
      return 'hsl(' + (d*120|0) + ', 100%, 50%)';
    },
    fieldStyle: function () {
      return {
        gridTemplate: 'repeat(' + this.stageHeight + ',20px) / repeat(' + this.stageWidth + ',20px)',
        MsGridRows: '(20px)[' + this.stageHeight + ']', MsGridColumns: '(20px)[' + this.stageWidth + ']',
        width: this.stageWidth*20 + 'px', height: this.stageHeight*20 + 'px'
      };
    },
    overlapTurtles: function () {
      return this.turtles.map(function (t) { return { x: t[0], y: t[1], nos: t[2] }; });
    },
    turtleStyle: function (overlapTurtle) {
      return {
        marginTop: this.nowFoods().some(function (f) { return f.x === overlapTurtle.x && f.y === overlapTurtle.y; })?'10px':'0',
        gridArea: [overlapTurtle.y + 1, overlapTurtle.x + 1, overlapTurtle.y + 2, overlapTurtle.x + 2].join(' / '),
        MsGridColumn: overlapTurtle.x + 1, MsGridRow: overlapTurtle.y + 1
      };
    },
    nowFoods: function () {
      return this.foods.map(function (f, i) { return { x: f[0], y: f[1], height: f[2], turn: f[3], no: i }; })
        .filter(function (f) { return f.turn >= vm.turn; });
    },
    foodStyle: function (food) {
      return {
        gridArea: [food.y + 1, food.x + 1, food.y + 2, food.x + 2].join(' / '),
        MsGridColumn: food.x + 1, MsGridRow: food.y + 1
      };
    }
  },
  watch: {
    // ステージが変更されたら、ターンを0にリセット
    stage: function (stage) {
      this.stage = Math.min(Math.max(stage, 0), this.stages.length - 1);
      this.turn = 0;
    },
    // ターンが変更されたら、スライダーも更新
    turn: function (turn) {
      const slider = document.getElementById('slider'),
            control = slider.firstChild.nextSibling;
      this.turn = Math.min(Math.max(turn, 0), this.turns.length - 1);
      control.style.left = (
        (slider.getBoundingClientRect().width - control.getBoundingClientRect().width)
        *this.turn/this.turns.length|0
      ) + 'px';
    },
    // 再生ボタンが押されたら、再生状態を変更する
    isPlay: function (isPlay) {
      if (isPlay) {
        this.timer = setTimeout(function loop() {
          if (vm.turn < vm.turns.length - 1) {
            vm.turn++;
            vm.timer = setTimeout(loop, 100);
          } else if (vm.playType == 1) {
            vm.turn = 0;
            vm.timer = setTimeout(loop, 100);
          } else if(vm.playType == 2) {
            if (vm.stage < vm.stages.length - 1) {
              vm.stage++
            } else vm.stage = 0;
            vm.timer = setTimeout(loop, 100);
          } else vm.isPlay = false;
        }, 15);
      } else clearTimeout(this.timer);
    }
  }
})
