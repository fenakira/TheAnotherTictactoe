#ifndef _APP_H_
#define _APP_H_

class App
{
public:
	static App& GetInstance() {
		static App instance;

		return instance;
	}

	int Run() {
		if( DxLib_Init() == -1 )		// ＤＸライブラリ初期化処理
		{
			return -1 ;			// エラーが起きたら直ちに終了
		}

		DrawPixel( 320 , 240 , 0xffff ) ;	// 点を打つ

		WaitKey() ;				// キー入力待ち

		DxLib_End() ;				// ＤＸライブラリ使用の終了処理

		return 0;
	}

private:
	App() {}
	App(App const&);
	App operator=(App const&);
};

#endif
/* _APP_H_ */
