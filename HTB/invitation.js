function makeInviteCode()
	{
	$.ajax(
		{
		type:"POST",dataType:"json",url:'/api/invite/how/to/generate',success:function(a)
			{
			console.log(a)
		}
		,error:function(a)
			{
			console.log(a)
		}
	}
	)
}